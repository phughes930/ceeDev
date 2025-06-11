// int tmult_ok(long x, long y, long *dest);
// int umult_ok(unsigned long x, unsigned long y, unsigned long *dest);

int tmult_ok_asm(long x, long y, long *dest)
{
    long p = x * y;
    *dest = p;

    return p > 0;
}

// int umult_ok_asm(unsigned long x, unsigned long y, unsigned long *dest)
// {
//     unsigned long p = x * y;
//     *dest = p;
//     return p > 0;
// }

int tmult_ok_asm(long x, long y, long *dest)
{
    int result;
    *dest = x * y;
    asm("setae %%bl             # Set low-order byte\n\t"
        "movzbl %%bl, %[val]    # Zero extend to be result"
        : [val] "=r"(result) /* Output       */
        :                    /* No inputs    */
        : "%bl"              /* Overwrites   */
    );
    return result;
}