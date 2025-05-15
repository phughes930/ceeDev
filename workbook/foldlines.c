#include <stdio.h>
#define MAXLINE 1000
#define MAXCOL  79

int getLine(char line[], int maxline);
void copy(char to[], char from[]);
int foldLine(char s[], int i);
int isWhitespace(char c);

/* Foldlines: fold lines at given column or at last white space */

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) /* there was a line */
        printf("%s\n", longest);
    return 0;
}

/* getline: read a line into s, return length */
int getLine(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        if (i >= MAXCOL) {
            i  = foldLine(i);
        }

        s[i] = c;
    if (c == '\n') {
        s[i] = c;
    }
    s[i] = '\0';
    return i;
}

int foldLine(char s[], int i)
{
    for (i; i >= 0; --i) {
        if (isWhitespace(s[i]) == 0) {
            s[i] = '\n';
            i++;
            break;
        } else if (i == 0) {
            s[MAXCOL] = '\n';
            i++;
            break;
        }
    }
    return i;
} 

int isWhitespace(char c)
{
    if (c == '\t' || c == ' ') {
        return 0;
    } else {
        return 1;
    }
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
