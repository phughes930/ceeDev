#include <stdio.h>
#define MAXLINE 1000
#define BIGLEN 80

int getline(char line[], int maxline);
void copy(char to[], char from[], int start);

/* print longest input line */

int main()
{
    int len;
    int total;
    char line[MAXLINE];
    char longlines[MAXLINE];

    total = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > BIGLEN) {
            copy(longlines, line, total);
            total += len;
        }
    if (total > 0) /* there was a line */
        printf("%s", longlines);
    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[], int start)
{
    int i;
    
    i = 0;
    while ((to[(start + i)] = from[i]) != '\0')
        ++i;
}
