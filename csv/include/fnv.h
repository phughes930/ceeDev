#ifndef FNV_H
#define FNV_H

#include <stdint.h>

uint32_t fnv1(uint8_t *src, size_t n_bytes, uint32_t offset_basis);
uint32_t fnv1a(uint8_t *src, size_t n_bytes, uint32_t offset_basis);
uint32_t get_fnv_offset();

#endif