#include <stdio.h>

void echo()
{
    char buf[8];
    gets(buf);
    puts(buf);
}

int main()
{
    echo();

    long int x = 12L;
    return 0;
}