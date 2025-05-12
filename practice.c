#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lenMyStr = 5;

struct abuf {
    char *s;
    int len;
};

void appendChar(struct abuf *, char);

int main()
{
    struct abuf *myString;
    myString->s = NULL;
    myString->len = 0;
    char c;

    getline(&myString->s, &myString->len, stdin);
    printf("%s", c);
    while ((c = getchar()) != EOF && c != '\n') {
        appendChar(myString, c);
    }
    if (c == '\n') {
        appendChar(myString, c);
    }
    appendChar(myString, '\0');

    printf("%s", myString);
}

void appendChar(struct abuf *str, char c)
{
    char *tmp = realloc((*str).s, (*str).len + 1);
    if (tmp == NULL) {
        return;
    } else {
        memcpy(&tmp[str->len], &c, 1);
        str->len += 1;
        str->s = tmp;
    }
}