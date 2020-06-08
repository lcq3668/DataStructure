#ifndef HEAP_H
#define HEAP_H
#include "node.h"
/* array  的 下标从 1 取起。当然这会浪费掉 下标为 0 的 空间*/
int adjustMaxHeap(nodeArray*  p , int i) ;
void buildMaxHeap(nodeArray* p );
node getMaxELe(nodeArray * p);
void insertMaxHeap(nodeArray* p , const node * ele);
node extractMaxELe(nodeArray * p);

int adjustMinHeap(nodeArray*  p , int i) ;
void buildMinHeap(nodeArray* p );
node getMinELe(nodeArray * p);
void insertMinHeap(nodeArray* p , const node * ele);
node extractMinELe(nodeArray * p);
#endif
