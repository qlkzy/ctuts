#include "cust_strtok.h"

static char *g_str;
static char *tp;
static char *ep;

static void init(const char *str);
static char *next(const char *delim);
static char *scan(const char *delim);
static int ceq(char c, const char *delim);

char *cust_strtok(const char *str, const char *delim)
{
    if (str)
        init(str);
    return next(delim);
}

static void init(const char *str)
{
    if (g_str) free(g_str);
    g_str = strdup(str);
    tp = ep = g_str;
}

static char *next(const char *delim)
{
    tp = ep;
    ep = scan(delim);
    return tp;
}

static char *scan(const char *delim)
{
    char *sp = tp;
    if (!*ep) {
        return 0;
    while (*ep && !ceq(*ep, delim))
        ep++;
    if (*ep)
        *ep = '\0';
    return ep++;
}

static int ceq(char c, const char *delim)
{
    while (*delim)
        if (*delim++ == c) return c;
    return 0;
}
