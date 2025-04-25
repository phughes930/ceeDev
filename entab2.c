/*
 * ENTAB program: take input lines and replace strings of whitespace with the
 * minimum number of tabstops. Using underscores _ to visualize the effect.
 *
 * Version 1 - implemented a function to execute when a \t is encountered
 *
 * Planning --------------------------------------------------------------------
 * -----------------------------------------------------------------------------
 * Four contexts:
 *  1. Not in whitespace, starting whitespace
 *  2. Not in whitespace, not starting whitespace
 *  3. In whitespace, not ending whitespace
 *  4. In whitespace, ending whitespace
 *
 * For each character:
 *  set start_whitespace = i
 *  set whitespace flag 
 *
 *      if char is whitespace, return 1
 *      if not whitespace, return 0
 *
 *  increment num_spaces 
 *      4 for a tab (detab)
 *      1 for a space
 * 
 * For each char, evaluate if whitespace
 *
 *  Function 1: setWhiteSpace(char c)
 *      Based on character, return value for whitespace flag
 *  Function 2: 
 */

#include <stdio.h>
#define MAXLINE     1000
#define TABSTOP     4 

int getLine(char s[], int lim);
void copy(char a[], char b[], int start);
int detab(char s[], int i, int tab);
int setWhiteSpaceFlag(char c);
int setWhiteSpaceStart(char c, int i, int start);

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
    int whiteSpaceFlag = 0;
    int whiteSpaceStart = 0;
    int numSpaces = 0;
    tab = TABSTOP;

    for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
        if (tab <= 0) {
            tab = TABSTOP;
        }
        whiteSpaceStart = setWhiteSpaceStart(c, i, whiteSpaceStart);

        if (c == '\t') {
            i = detab(s, i, tab);
            numSpaces += 4;
        } else if (c == ' ') {
            ++numSpaces;
            s[i] = c;
        } else if (isWhiteSpace(c) == 0 && whiteSpaceFlag == 1) {
            i = substituteWhiteSpace(s, i, numSpaces);
            numSpaces = 0;
            s[i] = c;
        } else {
            s[i] = c;
        }
        whiteSpaceFlag = setWhiteSpaceFlag(c);
        --tab;
    }
    if (c == '\n') {
        s[i] = '\n';
        ++i;
    }
    s[i] = '\0';

    return i;
}

int substituteWhiteSpace(char s[], int i, int numSpaces)
{
    int startWhiteSpace = i - numSpaces;
    int numTabs = numSpaces / TABSTOP;
    int nextTabStop; 
    numSpaces -= (numTabs * TABSTOP);
    int numChars = numSpaces + numTabs;

    /*
     * numSpaces will always be less than 4;
     *
     * if there's more than 1 space, tabs will be more efficient;
     *
     * after we use a tab, if it was less than 4 spaces, that amount will have
     * been accounted for by numSpaces; need to subtract that;
     */
    for (int j = startWhiteSpace; numTabs > 0 && numSpace > 0; ++j) {
        nextTabStop = (((j / TABSTOP) + 1 ) * TABSTOP) - j; 
        if (j == startWhiteSpace && nextTabStop == 1) {
            s[j] = ' ';
            --numSpaces;
        } else if (numTabs > 0) {
            s[j] = '\t';
            --numTabs;
            numSpaces -= (TABSTOP - nextTabStop);
            j += (nextTabStop - 1);
        } else {
            s[j] = ' ';
            --numSpaces;
        }
    }

   return startWhiteSpace + numChars; 
}

int setWhiteSpaceStart(char c, int i, int start)
{
    if (isWhiteSpace(c) != 0 && whiteSpaceFlag == 0) {
        start = i;
    } 
    return start;
}

int isWhiteSpace(char c)
{
    if (c == '\t' || c == ' ') {
       return 1;
    } else {
       return 0;
    }
} 

int setWhiteSpaceFlag(char c)
{
    /*
     * if char is whitespace, return 1
     * if not whitespace, return 0
     */
    int flag;
    if (c == '\t' || c == ' ') {
        flag = 1;
    } else {
        flag = 0;
    }
    return flag;
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
