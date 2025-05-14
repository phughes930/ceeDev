#define _GNU_SOURCE
#include "abuf.h"
#include "getPath.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct abuf *path = malloc(sizeof(struct abuf));
    path->len = 0;
    path->str = NULL;

    getPath(path);

    return 0;
}
