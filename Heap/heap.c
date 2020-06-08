#include"heap.h"
#define PARENT(N) ((N)/2)
#define LEFT(N) ((N)*2)
#define RIGHT(N) ((N)*2 + 1 )
#include<string.h>
int adjustMaxHeap(nodeArray*  p , int i) {
        while(i<= PARENT(p->len)) {
                int left = LEFT(i );
                int right = RIGHT(i);
                int tempMaxIndex = i;
                if(p->array[tempMaxIndex].probility< p->array[left].probility){
                        tempMaxIndex = left;
                }
                if(right <= p->len && p->array[tempMaxIndex].probility< p->array[right].probility){
                        tempMaxIndex = right;
                }
                if(tempMaxIndex != i){
                        node temp = p->array[i];
                        p->array[i] =  p->array[tempMaxIndex];
                        p->array[tempMaxIndex] = temp;
                        i = tempMaxIndex;
                }
                else{
                        return 0;
                }
        }
        return 1;
}

void buildMaxHeap(nodeArray* p ){
        for(int i = PARENT(p->len); i>=1 ;i--){
                adjustMaxHeap(p,i);
        }
}

node getMaxELe(nodeArray * p){
        return p->array[1];
}

void insertMaxHeap(nodeArray* p , const node * ele){
        p->len++;
        p->array[p->len] = *ele;
        for(int tempParent = PARENT(p->len); tempParent>=1;){
                if(adjustMaxHeap(p,tempParent) == 0){
                    break;
                }
                else{
                    tempParent = PARENT(tempParent);
                }
        }
}

node extractMaxELe(nodeArray * p){
        node ans = p->array[1];
        p->array[1] = p->array[p->len];
        p->len--;
        adjustMaxHeap(p,1);
        return ans;
}


int adjustMinHeap(nodeArray*  p , int i) {
        while(i<= PARENT(p->len)) {
                int left = LEFT(i );
                int right = RIGHT(i);
                int tempMinIndex = i;
                if(p->array[tempMinIndex].probility > p->array[left].probility){
                        tempMinIndex = left;
                }
                if(right <= p->len && p->array[tempMinIndex].probility > p->array[right].probility){
                        tempMinIndex = right;
                }
                if(tempMinIndex != i){
                        node temp = p->array[i];
                        p->array[i] =  p->array[tempMinIndex];
                        p->array[tempMinIndex] = temp;
                        i = tempMinIndex;
                }
                else{
                        return 0;
                }
        }
        return 1;
}

void buildMinHeap(nodeArray* p ){
        for(int i = PARENT(p->len); i>=1 ;i--){
                adjustMinHeap(p,i);
        }
}

node getMinELe(nodeArray * p){
        return p->array[1];
}

void insertMinHeap(nodeArray* p , const node * ele){
        p->len++;
        p->array[p->len] = *ele;
        for(int tempParent = PARENT(p->len); tempParent>=1;){
                if(adjustMinHeap(p,tempParent) == 0){
                    break;
                }
                else{
                    tempParent = PARENT(tempParent);
                }
        }
}


node extractMinELe(nodeArray * p){
        node ans = p->array[1];
        p->array[1] = p->array[p->len];
        p->len--;
        adjustMinHeap(p,1);
        return ans;
}