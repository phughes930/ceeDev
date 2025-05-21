#define _GNU_SOURCE
#include "llist.h"
#include <stdint.h>
#include <stdlib.h>

linkedlist initlist()
{
    linkedlist newlist = malloc(sizeof(struct linkedlist));
    newlist->numvals = 0;
    newlist->first = NULL;

    return newlist;
}

node initnode(uint32_t val)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->val = val;
    newnode->next = NULL;
}

void addnode(uint32_t val, linkedlist list)
{
    node new = initnode(val);
    if (list->first == NULL) {
        list->first = new;
    } else {
        node curr = list->first;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new;
    }
    list->numvals++;
}

void removenode(node to_remove, linkedlist list)
{
    node last, curr, next;
    last = NULL;
    curr = list->first;
    next = curr->next;

    while (curr != to_remove) {
        last = curr;
        curr = next;
        next = curr->next;
    }

    if (last != NULL) {
        last->next = next;
    } else {
        list->first = next;
    }

    free(curr);
    list->numvals--;
}