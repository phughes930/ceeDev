#include <stdio.h>
#define MAXLINE     1000

int getLine(char s[], int limit);
void copy(char from[], char to[]);

int main()
{
    int len;
    int longLen = 0;
    char longest[MAXLINE];
    char line[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > longLen) {
            longLen = len;
            copy(line, longest);
        }
    }

    if (longLen > 0) {
        printf("%s", longest);
    }

    return 0;
}


int getLine(char s[], int limit)
{
    int i, c;
    for (i = 0; i < limit && (c=getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = '\n';
        ++i;
    }

    s[i] = '\0';

    return i;
}


void copy(char from[], char to[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }

}
