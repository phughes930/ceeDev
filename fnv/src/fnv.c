#define _GNU_SOURCE
#include "fnvprime.h"
#include <ctype.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define FNV_PRIME      getfnvprime()
#define FNV_OFFSET_STR "chongo <Landon Curt Noll> /\\../\\"
// #define FNV_OFFSET     fnv1(FNV_OFFSET_STR, 32, 0)

uint32_t fnv1(uint8_t *src, size_t n_bytes, uint32_t offset_basis);
uint32_t fnv1a(uint8_t *src, size_t n_bytes, uint32_t offset_basis);
uint32_t get_fnv_offset();

uint32_t fnv1a(uint8_t *src, size_t n_bytes, uint32_t offset_basis) {
    uint32_t hash = get_fnv_offset();
    uint8_t oct;

    for (int i = 0; i < n_bytes; i++) {
        oct = *src++;
        hash ^= oct;
        hash *= FNV_PRIME;
    }
    return hash;
}

uint32_t fnv1(uint8_t *src, size_t n_bytes, uint32_t offset_basis) {
    uint32_t hash = offset_basis;
    uint8_t oct;

    for (int i = 0; i < n_bytes; i++) {
        oct = *src++;
        hash *= FNV_PRIME;
        hash ^= oct;
    }
    return hash;
}

uint32_t get_fnv_offset() {
    uint8_t *offset_str = (uint8_t *)FNV_OFFSET_STR;
    uint32_t offset = fnv1(offset_str, 32, 0);
    return offset;
}