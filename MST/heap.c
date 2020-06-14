#include"heap.h"
#define PARENT(N) ((N)/2)
#define LEFT(N) ((N)*2)
#define RIGHT(N) ((N)*2 + 1 )
int adjustMinHeap(edgePointerArray*  p , int i) {
        while(i<= PARENT(p->n)) {
                int left = LEFT(i );
                int right = RIGHT(i);
                int tempMinIndex = i;
                if(p->ep[tempMinIndex]->weight > p->ep[left]->weight){
                        tempMinIndex = left;
                }

                if(right <= p->n && p->ep[tempMinIndex]->weight > p->ep[right]->weight){
                        tempMinIndex = right;
                }
                if(tempMinIndex != i){
                        edge* temp = p->ep[i];
                        
                        p->ep[i] = p->ep[tempMinIndex];
                        
                        p->ep[tempMinIndex] = temp;
                        
                        i = tempMinIndex;
                }
                else{
                        return 0;
                }
        }
        return 1;
}

void buildMinHeap(edgePointerArray* p ){
    for(int i = PARENT(p->n); i>=1 ;i--){
                adjustMinHeap(p,i);
        }
}

edge* extractMinELe(edgePointerArray * p){
        edge* ans = p->ep[1];
        p->ep[1] = p->ep[p->n--];
        return ans;
}