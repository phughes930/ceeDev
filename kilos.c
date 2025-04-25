#include <stdio.h>

int main ()
{
    return 0;
}

int get_unit(char s[])
{
    printf("Input unit: ");
    scanf("%s", s);
    if (s == "lbs") {
        return 0;
    } else if (s == "kg") {
        return 1;
    } else {
        printf("bad unit! enter lbs or kg\n");
    }
}
