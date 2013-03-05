#include "tok.h"

#include <stdlib.h>

struct Tok {
    char *s;
    char *delim;
};

static int ceq(char c, const char *delim);

Tok strtok_mk(char *s, char *delim)
{
    Tok t = malloc(sizeof(*t));
    t->s = s;
    t->delim = delim;
}

char *strtok_next(Tok t)
{
    char *token;

    if (!t->s || !*t->s)
        return 0;

    while (*t->s && ceq(*t->s, t->delim))
        t->s++;

    token = t->s;
    
    while (*t->s && !ceq(*t->s, t->delim))
        t->s++;
    
    if (*t->s)
        t->s++ = '\0';
    
    return token;
}

void strtok_rm(Tok t)
{
    free(t);
}

static int ceq(char c, const char *delim)
{
    while (*delim)
        if (*delim++ == c) return c;
    return 0;
}
