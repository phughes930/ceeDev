#include <stdio.h>
#include <string.h>
#include "NumCmp.h"
#include "Swap.h"
#include "StrCmp.h"

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *), int foldcaps);
int numcmp(char *, char *);
int StrCmp(char *, char *);
int parseArg(char *, int *numeric, int *reverse, int *foldCaps);
void reverseArray(void *lineptr[], int numlines);
void strlower(char *s, int len, char *lowercase);

/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines;
    int numeric = 0;
    int reverse = 0;
    int foldCaps = 0;
    int i = 1;
    int argsOk;

    if (argc > 1)
    {
        while (i < argc && (argsOk = parseArg(argv[i++], &numeric, &reverse, &foldCaps)) != -1)
            ;

        if (argsOk != 0)
        {
            printf("Invalid argument");
            return -1;
        }
    }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))(numeric ? numcmp : StrCmp), foldCaps);
        if (reverse)
        {
            reverseArray((void **)lineptr, nlines);
        }
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("input too big to sort\n");
        return 1;
    }
}

int parseArg(char *arg, int *numeric, int *reverse, int *foldCaps)
{
    int i;
    for (i = 0; i < strlen(arg); i++)
    {
        switch (arg[i])
        {
        case '-':
            continue;
        case 'n':
            *numeric = 1;
        case 'r':
            *reverse = 1;
        case 'f':
            *foldCaps = 1;
        default:
            return -1;
        }
    }
    return 0;
}
/* qsort: sort v[left]...v[right] into increasing order */
void qsort(void *v[], int left, int right, int (*comp)(void *, void *), int foldCaps)
{
    int i, last;
    void Swap(void *v[], int, int);

    if (left > right)
    {
        return;
    }
    Swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
    {
        char v_i[strlen(v[i])];
        char v_left[strlen(v[left])];
        if (foldCaps)
        {
            strlower(v[i], strlen(v[i]), v_i);
            strlower(v[left], strlen(v[left]), v_left);
        }
        else
        {
            strcpy(v_i, v[i]);
            strcpy(v_left, v[left]);
        }
        if ((*comp)(v_i, v_left) < 0)
        {
            Swap(v, ++last, i);
        }
    }
    Swap(v, left, last);
    qsort(v, left, last - 1, comp, foldCaps);
    qsort(v, last + 1, right, comp, foldCaps);
}

void reverseArray(void *v[], int len)
{
    for (int i = 0; i < len / 2; i++)
    {
        Swap(v, i, len - 1 - i);
    }
}

void strlower(char *s, int len, char *lowercase)
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            lowercase[i] = s[i] + 26;
        }
        else
        {
            lowercase[i] = s[i];
        }
    }
    lowercase[i] = '\0';
}