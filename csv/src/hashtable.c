#include "fnv.h"
#include <stdint.h>

struct hashtable {
    uint32_t *hashmap;
    int keys;
};