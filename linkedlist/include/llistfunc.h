#ifndef LLISTFUNC_H
#define LLISTFUNC_H
#include <stdint.h>

linkedlist initlist();
node initnode(uint32_t val);
void addnode(uint32_t val, linkedlist list);
void removenode(node to_remove, linkedlist list);

#endif