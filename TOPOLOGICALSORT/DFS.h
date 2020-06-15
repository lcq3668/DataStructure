#ifndef DFS_H
#define DFS_H
struct vertex{
        struct vertex* next;
        int self;
        int s;
        int f;
};
typedef struct vertex vertex;

struct Graph{
        vertex * vs;
        int n;                                   // 点的个数
};
typedef struct Graph Graph;
struct  sequence{
        vertex** vp;
        int n;
};
typedef struct sequence sequence;
vertex** DFS(Graph g);
void DFSVisit(vertex* v,int * visited , int * time,sequence* sq);
#endif