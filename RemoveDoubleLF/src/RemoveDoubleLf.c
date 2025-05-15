#define _GNU_SOURCE
#include "abuf.h"
#include "getPath.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeDoubleLf(FILE *, struct abuf *);

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("Usage: RemoveDoubleLF <filepath> <outputname>\n");
        return -1;
    }
    char *path = argv[1];
    char *outputPath = argv[2];

    struct abuf *fileData = malloc(sizeof(struct abuf));
    fileData->len = 0;
    fileData->str = NULL;

    FILE *xmlFile = fopen(path, "r");
    removeDoubleLf(xmlFile, fileData);

    FILE *newFile = fopen(outputPath, "w");
    fwrite(fileData->str, fileData->len - 1, 1, newFile);

    return 0;
}

void removeDoubleLf(FILE *fstream, struct abuf *dest)
{
    char c;
    int lfCounter = 0;
    while ((c = fgetc(fstream)) != EOF) {
        char s[0];
        if (c == '\n' && lfCounter == 0) {
            lfCounter += 1;
            continue;
        } else if (c == '\n' && lfCounter == 1) {
            lfCounter -= 1;
            s[0] = c;
        } else {
            s[0] = c;
        }
        appendBuffer(dest, s, 1);
    }
    appendBuffer(dest, "\0", 1);
}