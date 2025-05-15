#include <stdio.h>

int power(int base, int power);

/* test power function */

int main() {
    int i;

    for (i = 0; i < 10; ++i) {
        printf("%d %d %d\n", i, power(2,i), power(-3,i));
    }
    
    return 0;
}

int power(int base, int power) {
    int total;

    total = 1;
    for (int i = 1; i <= power; ++i) {
        total = total * base;
    }
    
    return total;
} 
