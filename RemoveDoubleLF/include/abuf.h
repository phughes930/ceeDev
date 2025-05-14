#ifndef ABUF_H
#define ABUF_H

struct abuf {
    char *str;
    int len;
};

void appendBuffer(struct abuf *, char *, int);

#endif