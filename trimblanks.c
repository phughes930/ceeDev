#include <stdio.h>
#define MAXLINE 1000
#define BIGLEN 0 

int getLine(char line[], int maxline);
void copy(char to[], char from[], int start);

/* trim lines with trailing whitespace */

int main()
{
    int len;
    int total;
    char line[MAXLINE];
    char longlines[MAXLINE];

    total = 0;
    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > BIGLEN && line[0] != '*') {
            for (int count = 0; count < len; count ++) {
                printf("line[%d] - hex: [%x] - char: [%c]\n", count, line[count], line[count]);
            }
            copy(longlines, line, total);
            total += len;
        }
    } 
    if (total > 0) /* there was a line */
        printf("%s", longlines);
    return 0;
}

/* getline: read a line into s, return length */
int getLine(char s[], int lim)
{
    int c, i, j;
    int white; 

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        white = 0;
        s[i] = c;
        if (c == ' ' || c == '\t') {
            white = 1;
        } 
    }
    /* after this for-loop, i = total length of char array, white = 1 */

    if (c == '\n' && white != 0) {

        j = i - 1;

        while (j >= 0) {
            if (s[j] == ' ' || s[j] == '\t' || s[j] == EOF){
                 /* in this if statement, white changes to char index of current
                 * whitespace */
                white = j;
            } else {
                break;
            }
            --j;
        }
        int num_chars = i - white;

        i = white;
        s[i] = '*';
        ++i;
    } else if (c == '\n') {
        s[i] = '*';
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
