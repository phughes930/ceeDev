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

// Practice Problem 3.27
int test(int x, int y)
{
    int val = 4 * x;
    if (y > 0) {
        if (x < y)
            val = x - y;
        else
            val = x ^ y;
    } else if (y < -2)
        val = x + y;
    return val;
}

// Practice Problem 3.29
int switcher(int a, int b, int c)
{
    int answer;
    switch (a) {
    case 5:
        c = b ^ 15;
    case 0:
        answer = c + 112;
        break;
    case 2:
    case 7:
        answer = (c + b) << 4;
        break;
    case 4:
        answer = 4;
        break;
    default:
        answer = b;
    }
    return answer;
}

// Practice Problem 3.34
/* rfun: counts number of 1 bits in x */
int rfun(unsigned x)
{
    if (x == 0)
        return 0;
    unsigned nx = x >> 1;
    int rv = rfun(nx);
    return (x & 1) + rv;
}

// Practice Problem 3.38
#define N 16
typedef int fix_matrix[N][N];

/* Compute i,k of fixed matrix product */
int fix_prod_ele(fix_matrix A, fix_matrix B, int i, int k)
{
    int j;
    int result = 0;

    for (j = 0; j < N; j++)
        result += A[i][j] * B[j][k];

    return result;
}

/* Compute i,k of fixed matrix product */
int fix_prod_ele_opt(fix_matrix A, fix_matrix B, int i, int k)
{
    int *Arow = &A[i][0];
    int *Bptr = &B[0][k];
    int result = 0;
    int j;
    for (j = 0; j != N; j++) {
        result += Arow[j] * *Bptr;
        Btr += N;
    }
    return result;
}

void fix_set_diag(fix_matrix A, int val)
{
    int i;
    for (i = 0; i < N, i++)
        A[i][i] = val;
}

void fix_set_diag_opt(fix_matrix A, int val)
{
    int *Aptr = &A;
    int i;
    for (i = 0; i < N; i++) {
        *Aptr = val;
        Aptr += N + 1;
    }
}
