#include <stdio.h>

int pushtest()
{
    int result;
    asm(
        "movl   %%esp, %%eax        \n\t"
        "pushl  %%esp               \n\t"
        "popl   %%edx               \n\t"
        "subl   %%edx, %%eax        \n\t"
        "movl   %%eax, %[res]       \n\t"
        : [res] "=r"(result));

    return result;
}

int main()
{
    int x = pushtest();
    printf("result: %d\n", x);
}