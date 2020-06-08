#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include"../Heap/heap.h"
#include "haffmanCode.h"
node buildHuffmanTree(nodeArray* p);
huffmanCodeArray genHuffmanCodes(const node* p, int n);
void makeCode(const node*p, char * tempStorage,int tempLen,huffmanCodeArray*hca);
huffmanCodeArray pure2HuffmanCodes(nodeArray* p);
void freeNodes(const node*p,int n);
#endif