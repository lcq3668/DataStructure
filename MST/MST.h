#ifndef  MST_H
#define MST_H

#include"utility.h"
struct edge{
        double weight;
        int v1;            
        int v2;    
};
typedef struct edge edge;
struct edges{
        edge* e;
        int n;
};
typedef struct edges edges;
struct edgePointerArray{
    edge ** ep;
    int n;
};
typedef struct edgePointerArray edgePointerArray;
int isInSet( int v, int * set);
void enterSet(int v, int* set);
edges Prim(weightMatrix wm);
#endif