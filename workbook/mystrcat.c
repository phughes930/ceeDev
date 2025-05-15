#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void myStrCat(char *c, char *d);

int main()
{
    char *myString = NULL;
    size_t strSpace = 0;
    getline(&myString, &strSpace, stdin);

    char *newStr = NULL;
    size_t newSpace = 0;
    getline(&newStr, &newSpace, stdin);

    myStrCat(myString, newStr);
    printf("%s", myString);

    return 0;

}

void myStrCat(char *orig, char *add)
{
    while (*++orig != '\n')
        ;
    *orig++ = ' ';

    while ((*orig++ = *add++))
        ;
}
