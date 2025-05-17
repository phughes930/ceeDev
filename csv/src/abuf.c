#define _GNU_SOURCE
#include "buff.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void appendBuffer(struct abuf *ab, char *str, int len)
{
    char *new = realloc(ab->str, ab->len + len);
    if (new == NULL) {
        return;
    }
    memcpy(&new[ab->len], str, len);
    ab->str = new;
    ab->len += len;
}

struct abuf *initBuffer()
{
    struct abuf *newBuff = malloc(sizeof(struct abuf));
    newBuff->len = 0;
    newBuff->str = NULL;

    return newBuff;
}