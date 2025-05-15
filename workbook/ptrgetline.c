#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN  1000

int ptrGetLine(char *line, int lim);

int main ()
{
    int len;
    char *myLine = malloc(MAXLEN);
    // char myLine[MAXLEN]; 

    while ((len = ptrGetLine(myLine, MAXLEN)) > 0) {
        printf("Line received\n");
    }
 
    return 0;

}

int ptrGetLine(char *line, int lim)
{
    int c;
    char *ptrStart = line;

    for ( ; line - ptrStart < lim && (c = getchar()) != EOF && c != '\n'; line++) {
        *line = c;
    }
    if (c == '\n') {
        *line++ = c; 
    }
    *line = '\0';
    return line - ptrStart;
}

