/*
 * PREPROCESSOR
 */
#include <stdio.h>
#include <string.h>

#define ALLOCSIZE   10000
#define MAXLINES    5000
#define MAXLEN      1000

/*
 * EXTERNAL VARIABLES
 */
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf
char *lineptr[MAXLINES];


/*
 * FUNCTION DECLARATIONS
 */
char *alloc(int n);
void afree(char *p);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
int getLines(char *line, int lim);

int main ()
{
    int nlines;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

/* 
 * QUICKSORT
 */
void qsort(char *lineptr[], int left, int right)
{


/*
 * ALLOCATION FUNCTIONS
 */
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else {
        return 0;
    }
}

void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp -= p;
}

/*
 * READLINES
 */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    while ((len = getLine(line, MAXLEN)) > 0) {
        if (nlines >= MAXLINES || (p = alloc(len)) == NULL) {
            return -1;
        } else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

int writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
}

int getLine(char *line, int lim)
{
    int i, c;

    for (i = 0; i < line && (c = getchar()) != EOF && c != '\n') {
        *(line + i) = c;
    }
    if (c == '\n') {
        *(line + i) = c;
        ++i;
    }
    *(s + i) = '\0';
    return i;
}


