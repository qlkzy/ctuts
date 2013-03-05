#include "stok.h"

static char *end = 0;

static int ceq(char c, const char *delim);

char *stok(char *s, const char *delim)
{
    s = s ? s : end;

    if (!s || !*s)
        return 0;

    while (*s && ceq(*s, delim))
        s++;

    end = s;
    
    while (*end && !ceq(*end, delim))
        end++;
    
    if (*end)
        *end++ = '\0';

    return s;
}


static int ceq(char c, const char *delim)
{
    while (*delim)
        if (*delim++ == c) return c;
    return 0;
}
