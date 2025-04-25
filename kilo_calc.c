#include <stdio.h>
#include <string.h>

#define MAXLINE     1000
int getLine(char s[], int limit);
void copy(char from[], char to[]);
int getUnit(char *s);
void printInputString(char *s);

int main()
{
    int len, unit;
    char line[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0) {
        unit = getUnit(line);
        printf("%d\n", unit);    
    }

    return 0;
}

void printInputString(char *s)
{
    printf("%d", strlen(s));
    /*
    int i = 0;
    while (*(s+i) != '\0') {
        printf("%c", *(s+i));
        ++i;
    }
    */
}


int getLine(char s[], int limit)
{
    int i, c;
    for (i = 0; i < limit && (c=getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    /* 
    * if (c == '\n') {
    *    s[i] = '\n';
    *   ++i;
    * }
    */

    s[i] = '\0';

    return i;
}

int getUnit(char *s) 
{
   


    if (strcmp(s, "kgs")) {
        return 1;
    } else if (strcmp(s, "lbs")) {
        return 0;
    } else {
        return -1;
    }

}

