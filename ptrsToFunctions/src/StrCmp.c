#include <string.h>

/* StrCmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int StrCmp(char *s, char *t)
{
    for (; *s == *t; s++, t++)
    {
        if (*s == '\0')
        {
            return 0;
        }
    }
    return *s - *t;
}