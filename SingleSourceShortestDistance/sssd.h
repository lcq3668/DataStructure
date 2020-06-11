#ifndef SSSD_H
#define SSSD_H
#include"utility.h"
struct vertex{
        double distance;
        int prefix;                  // 最短路径的 中的 该点的前继
        int self;
};
typedef struct vertex vertex;
struct vertexPointerArray{
    vertex ** vp;
    int n;
};
typedef struct vertexPointerArray vertexPointerArray;
vertex* findSSSDMat(weightMatrix wm,int s);
vertex* findSSSDList(weightList wl, int s);
#endif
