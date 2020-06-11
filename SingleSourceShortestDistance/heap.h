#ifndef HEAP_H
#define HEAP_H
#include"sssd.h"
int adjustMinHeap(vertexPointerArray*  p , int i) ;
void buildMinHeap(vertexPointerArray* p );
vertex* extractMinELe(vertexPointerArray * p);
#endif