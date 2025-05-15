/*
 * ENTAB program: take input lines and replace strings of whitespace with the
 * minimum number of tabstops. Using underscores _ to visualize the effect.
 *
 * Version 2 - implemented a function to execute when a \t is encountered
 *
 * Planning --------------------------------------------------------------------
 * -----------------------------------------------------------------------------
 *  Case 1: if tabstop = 0:
 *      if it's a tab:
 *          use a tab
 *          tabstop = 0
 *      if it's a space:
 *          use a space
 *          increment spaceCounter
 *      if it's a char:
 *          check spaceCounter --> if have prior spaces, replace
 *
 *  Case 2: if tabstop == 1:
 *      if it's a tab:
 *          use a space
 *          increment spaceCounter
 *      if it's a space:
 *          use a space
 *          increment spaceCounter
 *      if it's a char:
 *          check spaceCounter --> if have prior spaces, replace
 *
 *  Case 3: if tabstop > 1:
 *      if it's a tab:
 *          use a tab
 *          tabstop = 0;
 *      if it's a space:
 *          use a space
 *      if it's a char:
 *          check spaceCounter --> if have prior spaces, replace
*/

#include <stdio.h>
#define MAXLINE     1000
#define TABSTOP     4 

int getLine(char s[], int lim);
int entab(char s[], char c, int i);
int detab(char s[], int i);
int replaceSpaces(char s[], int i);
void copy(char a[], char b[], int start);
int spaceCounter = 0;
int tab = TABSTOP;

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
    extern int tab;
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
        if (tab <= 0) {
            tab = TABSTOP;
        }
        i = entab(s, c, i); 
        --tab;
    }
    if (c == '\n') {
        s[i] = '\n';
        ++i;
    }
    s[i] = '\0';

    return i;
}

int entab(char s[], char c, int i)
{
    extern int spaceCounter;
    extern int tab;
    if (tab == 0) {                     // Case 1
        if (c == ' ') {
            ++spaceCounter;
        } else {
            i = replaceSpaces(s, i);
        }
    } else if (tab == 1) {              // Case 2
        if (c == '\t') {
            c = ' ';
            ++spaceCounter;
        } else if (c == ' ') {
            ++spaceCounter;
        } else {
            i = replaceSpaces(s, i);
        }
    } else {                            // Case 3
        if (c == '\t') {
            tab = 0;
        } else if (c == ' ') {
            ++spaceCounter;
        } else {
            i = replaceSpaces(s, i);
        }
    }
    s[i] = c;
    return i;
}

int replaceSpaces(char s[], int i)
{
    extern int spaceCounter;
    if (spaceCounter > 1) {
        i = i - spaceCounter;
        i = detab(s, i);
        ++i;
    }
    spaceCounter = 0;
    return i;
}

int detab(char s[], int i)
{
    extern int tab;
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
