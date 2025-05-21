#define _GNU_SOURCE
#include "llist.h"
#include "llistfunc.h"
#include <stdint.h>
#include <stdio.h>

int main()
{
    linkedlist list = initlist();
    for (uint32_t i = 0; i < 5; i++) {
        addnode(i, list);
    }

    removenode(list->first, list);
    node curr = list->first;
    while (curr->next != NULL) {
        printf("val '%u'\n", curr->val);
        node next = curr->next;
        curr = next;
    }

    return 0;
}