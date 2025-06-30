#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_HASH_TABLE_SIZE 0xEFFFFFFF

struct hash_table_struct {
    uint32_t **arr;
};

typedef struct hash_table_struct *hashtable;

hashtable make_hash_table(int size) {
    if (size > MAX_HASH_TABLE_SIZE) {
        return NULL;
    }

    size_t hash_struct_size = sizeof(struct hash_table_struct);
    hashtable new = (hashtable)malloc(hash_struct_size);
    uint32_t **arr = (uint32_t **)malloc(4 * size);
    new->arr = arr;

    return new;
}

void add_value(hashtable table, uint32_t key, uint32_t address) {
    table->arr[key] = (void *)address;

    size_t n = sizeof(unsigned int *);
}
