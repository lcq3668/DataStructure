#include"sssd.h"
#include<stdlib.h>
#include<limits.h>
#include"heap.h"
//#include"stdio.h"
vertex* findSSSDMat(weightMatrix wm, int s){
    /* 用的是 Dijkstra 算法*/
        if(s >= wm.n){

                return NULL;
        }
        vertex* ans = (vertex*)malloc(sizeof(vertex) *wm.n);
        if(ans == NULL){
                return NULL;
        } 
        vertex** vp =  (vertex**)malloc(sizeof(vertex*) *(wm.n+1));     // 多准备一个空间，这是见建堆的算法要求的
        if(vp == NULL){
                return NULL;
        } 
        for(int i = 0; i<wm.n; i++){ 
                ans[i].distance = (double)INT_MAX;
                ans[i].prefix = -1;
                ans[i].self = i;
        }

        /* 设置 起始点的距离和前继*/
        ans[s].distance = 0.0;
        ans[s].prefix = s;

        for(int i = 0; i<wm.n; i++){
                vp[i+1] = ans + i;
        }
        vertexPointerArray vpa;
        vpa.n = wm.n;
        vpa.vp = vp;
        buildMinHeap(&vpa);
        while(vpa.n>0){
            vertex* temp = extractMinELe(&vpa);
            printf("now point is : %d\n",temp->self);
            if(temp->distance == (double)INT_MAX){
                break;
            }
            for(int j = temp->self, i = 0; i<wm.n;i++){ 
                    if(wm.weights[j * wm.n + i] != (double)INT_MAX){
                            if(ans[i].distance > ans[j].distance + wm.weights[j*wm.n+i]){
                                    ans[i].distance = ans[j].distance + wm.weights[j*wm.n+i];
                                    ans[i].prefix = j;
                            }
                    }
            }
            printf("now n is : %d\n",vpa.n);
            buildMinHeap(&vpa);
        }
        free(vp);
        return  ans;
}


vertex* findSSSDList(weightList wl, int s){
        if(s >= wl.n){
                printf("in s error\n");
                return NULL;
        }
        vertex* ans = (vertex*)malloc(sizeof(vertex) *wl.n);
        if(ans == NULL){
                printf("in ans error\n");
                return NULL;
        } 
        vertex** vp =  (vertex**)malloc(sizeof(vertex*) *(wl.n+1));     // 多准备一个空间，这是见建堆的算法要求的
        if(vp == NULL){
                printf("in vp error\n");
                return NULL;
        } 
        for(int i = 0; i<wl.n; i++){ 
                ans[i].distance = (double)INT_MAX;
                ans[i].prefix = -1;
                ans[i].self = i;
        }

        /* 设置 起始点的距离和前继*/
        ans[s].distance = 0.0;
        ans[s].prefix = s;

        for(int i = 0; i<wl.n; i++){
                vp[i+1] = ans + i;
        }
        vertexPointerArray vpa;
        vpa.n = wl.n;
        vpa.vp = vp;
        buildMinHeap(&vpa);
        while(vpa.n>0){
                vertex* temp = extractMinELe(&vpa);
                if(temp->distance == (double)INT_MAX){
                        break;
                }
                int j = temp->self;
                
                node* nv = wl.vertex[j];
                
                while(nv != NULL){
                        int i = nv->v;
                        if(ans[i].distance > ans[j].distance + nv->weight){
                                ans[i].distance = ans[j].distance + nv->weight;
                                ans[i].prefix = j;
                        }
                        nv = nv->next;
                }
                /*
            for(int j = temp->self, i = 0; i<wm.n;i++){ 
                    if(wm.weights[j * wm.n + i] != (double)INT_MAX){
                            if(ans[i].distance > ans[j].distance + wm.weights[j*wm.n+i]){
                                    ans[i].distance = ans[j].distance + wm.weights[j*wm.n+i];
                                    ans[i].prefix = j;
                            }
                    }
            }
            */
            buildMinHeap(&vpa);
        }
        free(vp);
        return  ans;
}