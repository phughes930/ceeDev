#ifndef LLIST_H
#define LLIST_H
#include <stdint.h>

struct node {
    uint32_t val;
    void *next;
};

typedef struct node *node;

struct linkedlist {
    int numvals;
    void *first;
};

typedef struct linkedlist *linkedlist;

#endif