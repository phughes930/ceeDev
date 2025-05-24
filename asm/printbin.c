#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct abuf {
    char *str;
    int len;
};

typedef struct abuf *abuf;

abuf initbuff()
{
    abuf ab = malloc(sizeof(struct abuf));
    ab->str = NULL;
    ab->len = 0;

    return ab;
}

int abappend(abuf buff, char *str, int len)
{
    char *new = realloc(buff->str, buff->len + len);
    if (new == NULL) {
        return -1;
    }
    memcpy(&new[buff->len], str, len);
    buff->len += len;
    buff->str = new;
    return 0;
}

char *hexstr(unsigned char c)
{
    unsigned char original = c;
    // printf("original = %.2x\n", c);
    char *str = malloc(sizeof(char) * 2);
    int count = 1;
    while (c > 0) {
        // printf("c = %.2x\t", c);

        unsigned int digit = c % 16;
        // printf("digit = %u\t", digit);

        char n;
        if (digit >= 0 && digit <= 9) {
            n = '0' + (int)digit;
        } else {
            int alph = (int)digit - 10;
            n = 'A' + alph;
        }
        // printf("char = '%c'\n", n);

        if (original > 15) {
            str[count--] = n;
            c -= digit;
            c /= 16;
        } else {
            str[0] = '0';
            str[1] = n;
            break;
        }
    }
    if (original == 0) {
        str[0] = '0';
        str[1] = '0';
    }
    // printf("string = '%s'\n", str);
    return str;
}

int main(int argc, char **argv)
{
    // if (argc < 2) {
    //     printf("Usage: printbin <filepath>\n");
    // }

    // FILE *binfile = fopen(argv[2], "r");
    // printf("file size: %u\n", sizeof(*binfile));
    unsigned char c;
    int i = 0;
    int returnval;
    abuf file = initbuff();
    while (i < 216) {
        c = getc(stdin);
        char *str = hexstr(c);
        // printf(" %s", str);
        returnval = abappend(file, str, 2);
        abappend(file, " ", 1);
        // printf("%d\n", returnval);
        i++;
        if (!(i % 10)) {
            // printf("\n");
            returnval = abappend(file, "\n", 1);
            // printf("%d\n", returnval);
        }
    }
    abappend(file, "\0", 1);
    printf("%s", file->str);
    printf("\n");
    FILE *out = fopen("./binout.txt", "w");
    fwrite(file->str, sizeof(char) * 2, file->len, out);
}