#ifndef ABUF_H
#define ABUF_H

struct abuf *initBuffer();
void appendBuffer(struct abuf *ab, char *str, int len);

#endif