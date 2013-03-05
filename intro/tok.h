#ifndef TOK_H
#define TOK_H

typedef struct Tok *Tok;

Tok strtok_mk(char *s, char *delim);
char *strtok_next(Tok t);
void strtok_rm(Tok t);

#endif /* TOK_H */
