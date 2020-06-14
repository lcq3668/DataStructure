#ifndef HEAP_H
#define HEAP_H
#include"MST.h"
int adjustMinHeap(edgePointerArray*  p , int i) ;
void buildMinHeap(edgePointerArray* p );
edge* extractMinELe(edgePointerArray * p);
#endif