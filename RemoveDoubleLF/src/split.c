#include "abuf.h"
#include <stdio.h>

int split(struct abuf *string, struct abuf **dest, char delim)
{
    int i = 0;
    int numPieces = 0;
    char c;
    while (c != '\0') {
        printf("Entering split outer loop\n");
        struct abuf *new = malloc(sizeof(struct abuf));
        new->len = 0;
        new->str = NULL;

        while ((c = string->str[i++]) != delim && c != '\0') {
            char new_char[0];
            printf("%c\n", c);
            new_char[0] = c;
            appendBuffer(new, new_char, 1);
        }
        appendBuffer(new, "\0", 1);
        dest[numPieces++] = new;
    }

    return numPieces;
}