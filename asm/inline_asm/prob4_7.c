#include <stdio.h>

int poptest()
{
    int result;
    asm(
        "pushl  $0xabcd             \n\t"
        "popl   %%esp               \n\t"
        "movl   %%esp, %[res]       \n\t"
        : [res] "=r"(result));

    return result;
}

int main()
{
    int x = poptest();
    printf("result: %x\n", x);
}