#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>

struct abuf {
    char *str;
    int len;
};

void appendBuffer(struct abuf *buffer, char *str, int len)
{
    char *new = realloc(buffer->str, buffer->len + len);
    if (new == NULL) {
        return;
    }
    memcpy(&new[buffer->len], str, len);
    buffer->len += len;
    buffer->str = new;
}