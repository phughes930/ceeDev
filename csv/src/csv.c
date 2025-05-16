#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCOLS 1000
// parse path from argc
// read headers
// num_cols = num_headers
// parse headers
// rows = num_lines - 1

/* csv: print headers, num_cols, num_rows from a file */
struct abuf {
    char *str;
    int len;
};

void appendBuffer(struct abuf *, char *, int);
int parseHeaders(struct abuf **, struct abuf *, char);

int main(int argc, void **argv)
{
    if (argc < 1 || argc > 2) {
        printf("Error: improper usage\nProper usage: csv <path>");
        return -1;
    }

    char *path = argv[1];
    FILE *csv = fopen(path, "r");

    struct abuf *headerArr[MAXCOLS];
    struct abuf *headers = malloc(sizeof(struct abuf));
    headers->str = NULL;
    headers->len = 0;

    size_t headerSize = 0;
    getline(&(headers->str), &headerSize, csv);
    headers->len = strlen(headers->str);

    int numCols = parseHeaders(headerArr, headers, ',');

    printf("%d columns\n", numCols);
    printf("Column names:\n");
    for (int i = 0; i < numCols; i++) {
        printf("\t%s", headerArr[i]);
    }

    return 0;
}

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

int parseHeaders(struct abuf **destArr, struct abuf *headerData, char delim)
{
    int i = 0;
    int numCols = 0;
    while (headerData->str[i] != '\0') {
        struct abuf *currHeader = malloc(sizeof(struct abuf));
        currHeader->len = 0;
        currHeader->str = NULL;
        char c;
        int quoteFlag = 0;
        int colIter = 0;

        while ((c = headerData->str[i++]) != delim) {
            char s[0];
            switch (c) {
            case '"':
                if (colIter == 0) {
                    quoteFlag = !quoteFlag;
                    continue;
                } else if (quoteFlag && headerData->str[i + 1] == delim) {
                    quoteFlag != quoteFlag;
                    continue;
                } else if (quoteFlag && headerData->str[i + 1] == '"') {
                    s[0] = c;
                    i++;
                }
            case ',':
                if (quoteFlag) {
                    s[0] = c;
                } else {
                    break;
                }
            default:
                s[0] = c;
            }
            appendBuffer(currHeader, s, 1);
            colIter++;
        }
        destArr[numCols++] = currHeader;
    }
    return numCols;
}