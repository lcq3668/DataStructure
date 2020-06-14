#include"MST.h"
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include"heap.h"
edges Prim(weightMatrix wm ){
        int s = 0;
        edge* ans = (edge*)malloc(sizeof(edge) *(wm.n));
        edges es;
        if(ans == NULL){
                printf("could not malloc for edge* ans \n");
                exit(0);
        } 
        es.e = ans + 1;                                                                 // 第0 个不需要
        es.n = wm.n - 1;
        int* set = (int*)malloc(sizeof(int)*wm.n);         // 用以描述 点是否合并到 属于MST的集合 
        if( set ==  NULL){
                printf("could not malloc for int* set \n");
                exit(0);
        }
        edge** ep =  (edge**)malloc(sizeof(edge*) *(wm.n+1));     // 多准备一个空间，这是见建堆的算法要求的
        if(ep == NULL){
                printf("could not malloc for edge** ep \n");
                exit(0);
        } 
        for(int i = 0; i<wm.n; i++){ 
                ans[i].weight = (double)INT_MAX;   // distance 就是 key ，代表离 集合的最短距离
                ans[i].v2 = -1;                                         // v2 代表邻接点
                ans[i].v1 = i;                                            // v1 代表自身
                set[i] = 0;
        }
 
        /* 设置 起始点的距离和前继*/
        ans[s].weight = 0.0;
        ans[s].v2 = s;

        for(int i = 0; i<wm.n; i++){
                ep[i+1] = ans + i;
        }
        edgePointerArray epa;
        epa.n = wm.n;
        epa.ep = ep;
        buildMinHeap(&epa);
        while(epa.n>0){
            edge* temp = extractMinELe(&epa);
            printf("now point is : %d\n",temp->v1);
            /*
            if(temp->weight == (double)INT_MAX){
                break;
            }
            */
           enterSet(temp->v1,set);
            for(int j = temp->v1, i = 0; i<wm.n;i++){ 
                    if(!isInSet(i,set) && wm.weights[j * wm.n + i] != (double)INT_MAX){
                            if(ans[i].weight > wm.weights[j*wm.n+i]){
                                    ans[i].weight = wm.weights[j*wm.n+i];
                                    ans[i].v2 = j;
                            }
                    }
            }
            printf("now n is : %d\n",epa.n);
            buildMinHeap(&epa);
        }
        free(ep);
        free(set);
        return  es;
}




int isInSet( int v, int * set){
        return set[v];
}
void enterSet(int v, int* set){
        set[v] = 1;
}
