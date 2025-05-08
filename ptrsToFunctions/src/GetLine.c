#include <stdio.h>

int getLine(char *line, int maxlines)
{
    int c, i;
    i = 0;
    while (i < maxlines && (c = getchar()) != EOF && c != '\n')
    {
        line[i++] = c;
    }
    if (c == '\n')
    {
        line[i++] = c;
    }
    line[i] = '\0';

    return i;
}