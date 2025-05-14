#include "abuf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000

void getPath(struct abuf *filePath)
{
    printf("Please input path to file: ");
    char *path = malloc(MAXLEN);
    int len;
    scanf("%s", path);
    len = strlen(path);

    appendBuffer(filePath, path, len);
}