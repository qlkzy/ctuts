#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char prefix[256];
char buf[4096];
char *pb = buf;

#define NELEM(x) (sizeof(x) / sizeof(x[0]))

void process_line()
{
    *pb++ = '\0';

    switch (buf[0]) {
    case ':':
        strncpy(prefix, buf+1, NELEM(prefix));
        break;
    case '\0':
        break;
    default:
        printf("\\newcommand{\\%s%s}{\\texttt{%s}}\n",
               prefix, buf, buf);
    }

    pb = buf;
}

void process_file(const char *path)
{
    FILE *f = fopen(path, "r");
    int ch;

    if (!f) {
        fprintf(stderr, "Could not open file with path %s\n", path);
        abort();
    }
    
    while ((ch = fgetc(f)) != EOF &&
           pb - buf < 10 )
        if (ch == '\n')
            process_line();
        else if (isspace((char)ch))
            continue;
        else
            *pb++ = (char)ch;


    process_line();

    fclose(f);
}

int main(int argc, char *argv[])
{
    int i;

    for (i = 1; i < argc; i++)
        process_file(argv[i]);

    return 0;
}
