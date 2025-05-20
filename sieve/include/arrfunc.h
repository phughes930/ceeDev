#ifndef ARRFUNC_H
#define ARRFUNC_H

struct intarr *initintarr();
void appendint(struct intarr *array, int newval);
int binsearch(int *arr, int low, int high, int find);
void removeindex(struct intarr *array, int index);
void removeval(struct intarr *array, int remval);

#endif