/*
 * Detab program: take input lines and replace tabs with space to the next
 * tabstop. Using underscores _ to visualize the effect.
 *
 * Version 2 - implemented a function to execute when a \t is encountered
 */

#include <stdio.h>
#define MAXLINE     1000
#define TABSTOP     4 

int getLine(char s[], int lim);
void copy(char a[], char b[], int start);
int detab(char s[], int i, int tab);

int main ()
{
    char line[MAXLINE];
    char allines[MAXLINE];
    int len;
    int totallen = 0;

    while ((len = getLine(line, MAXLINE)) > 0) {
        copy(allines, line, totallen);
        totallen += len;
    }

    if (totallen > 0) {
        printf("%s", allines);
    }

    return 0;
}

int getLine(char s[], int lim)
{
    int c, i, tab;
    tab = TABSTOP;
    for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
        if (tab <= 0) {
            tab = TABSTOP;
        }

        if (c == '\t') {
            i = detab(s, i, tab);
        } else {
            s[i] = c;
        }

        --tab;
    }
    if (c == '\n') {
        s[i] = '\n';
        ++i;
    }
    s[i] = '\0';

    return i;
}
int detab(char s[], int i, int tab)
{
    while (tab > 0) {
        s[i] = '_';
        --tab;
        ++i;
    }
    --i;

    return i;
}

void copy(char to[], char from[], int start)
{
    int i;

    i = 0;
    while ((to[start + i] = from[i]) != '\0') {
        ++i;
    }
}
