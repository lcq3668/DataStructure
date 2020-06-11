#include"heap.h"
#define PARENT(N) ((N)/2)
#define LEFT(N) ((N)*2)
#define RIGHT(N) ((N)*2 + 1 )
int adjustMinHeap(vertexPointerArray*  p , int i) {
        while(i<= PARENT(p->n)) {
                int left = LEFT(i );
                int right = RIGHT(i);
                int tempMinIndex = i;
                if(p->vp[tempMinIndex]->distance > p->vp[left]->distance){
                        tempMinIndex = left;
                }

                if(right <= p->n && p->vp[tempMinIndex]->distance > p->vp[right]->distance){
                        tempMinIndex = right;
                }
                if(tempMinIndex != i){
                        vertex* temp = p->vp[i];
                        
                        p->vp[i] = p->vp[tempMinIndex];
                        
                        p->vp[tempMinIndex] = temp;
                        
                        i = tempMinIndex;
                }
                else{
                        return 0;
                }
        }
        return 1;
}

void buildMinHeap(vertexPointerArray* p ){
    for(int i = PARENT(p->n); i>=1 ;i--){
                adjustMinHeap(p,i);
        }
}

vertex* extractMinELe(vertexPointerArray * p){
        vertex* ans = p->vp[1];
        p->vp[1] = p->vp[p->n--];
        return ans;
}