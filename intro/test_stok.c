#include "stok.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NELEM(x) (sizeof(x) / sizeof(x[0]))

const char *t0exp[] = {0};
const char *t1exp[] = {"This", "is", "a", "test", 0};
const char *t2exp[] = {"This", "is", "another", "test", 0};

struct tc {
    const char *str;
    const char *del;
    const char **exp;
} cases[] =  {
    {
        .str = "",
        .del = " ",
        .exp = t0exp
    },
    {
        .str = "This is a test",
        .del = " ",
        .exp = t1exp
    },
    {
        .str = "This,is,;another;,,,test;",
        .del = ",;",
        .exp = t2exp
    }
};

#define FAIL(...)                               \
    do {                                        \
        fprintf(stderr, __VA_ARGS__);           \
        abort();                                \
    } while (0)

static void runtest(int num, const char *str, const char *del, const char *exp[])
{
    /* we need to strdup our const strs so that strtok can modify them */
    char *s = strdup(str);
    char *tok;
    const char **ep;

    fputc('.', stderr);
    
    tok = stok(s, del);

    for (ep = exp; *ep; ep++) {
        if (!tok)
            FAIL("Test %d: Expected token '%s', got null pointer\n", num, *ep);
        else if (strcmp(*ep, tok))
            FAIL("Test %d: Expected token '%s', got token '%s'\n", num, *ep, tok);
        tok = stok(NULL, del);
    }
        
    if (tok != 0)
        FAIL("Test %d: Expected null pointer, got token '%s'\n", num, tok);

    free(s);
}

int main()
{
    int i;

    if (stok(NULL, NULL))
        FAIL("Returned a non-null pointer when initially passed two null pointers\n");

    for (i = 0; i < NELEM(cases); i++)
        runtest(i, cases[i].str, cases[i].del, cases[i].exp);

    printf("\n%d tests run\n", i);
    return 0;
}
