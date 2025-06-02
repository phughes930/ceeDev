int loop_while(int a, int b)
{
    int result = 1;
    while (a < b) {
        result *= (a + b);
        a++;
    }
    return result;
}

int goto_loop_while(int a, int b)
{
    int result = 1;
    int t = a < b;
    if (!t)
        goto done;

    if (t)
        goto loop;

loop:
    int sum = a + b;
    a *= sum;
    a++;
    t = a < b;
    if (t)
        goto loop;

done:
}
/* fun_a: computes parity of x */
int fun_a(unsigned x)
{
    int val = 0;
    while (x) {
        val = x ^ val;
        x >> 1;
    }
    return val & 1;
}

int fun_b(unsigned x)
{
    int val = 0;
    int i;
    for (i = 0; i < 32; i++) {
        int j = 2val;
        val = x;
        val &= 1;
        val |= j;
        x >> 1;
    }
    return val;
}

void prob3_24()
{
    {
        int sum = 0;
        int i;
        for (i = 0; i < 10; i++) {
            if (i & 1)
                continue;

            sum += i;
        }
    }

    /* translate to while loop */
    {
        int sum = 0;
        int i = 0;       // init statement
        while (i < 10) { // test expression
            if (i & 1)   // body start
                continue;
            sum += i; // body end
            i++;      // update expression
        }
        /* problem is that i doesn't update if
           the if statement evaluates to true */
    }
    /* can fix like this */
    {
        int sum = 0;
        int i = 0;       // init statement
        while (i < 10) { // test expression
            if (i & 1)   // body start
                goto finish;
            sum += i; // body end
        finish:
            i++; // update expression
        }
        /* problem is that i doesn't update if
           the if statement evaluates to true */
    }
}
