#include"haffmanTree.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
void freeNodes(const node* p,int n){
        // p 指向 栈空间
        node** temp =(node**)malloc(sizeof(node*) * (2*n -1));
        int len = 0;
        if(temp == NULL){
                printf(" malloc failed\n");
                exit(0);
        }
        temp[len++] = p->right;
        temp[len++] = p->left;
        node* tempRoot;
        while(len>0){
                tempRoot = temp[--len];
                if(tempRoot->left != NULL){                 // 要么没有 子节点， 要么有两个子节点
                        temp[len++] = tempRoot->right;
                        temp[len++] = tempRoot->left;
                }
                //printf("In freeNodes   ");
                //printf("%lf,%ld\n",tempRoot->probility,tempRoot);
                free(tempRoot);
        }
        free(temp);
}
node buildHuffmanTree(nodeArray* p){
        while(p->len>1){
                node* temp1 = (node*)malloc(sizeof(node));
                node* temp2 = (node*)malloc(sizeof(node));
                *temp1 = extractMinELe(p);
                // printf("%lf , %ld , %ld , %c \n",temp1->probility,temp1->left,temp1->right,temp1->letter);
                *temp2 = extractMinELe(p);
                // printf("%lf , %ld , %ld , %c \n",temp2->probility,temp2->left,temp2->right,temp2->letter);
                node temp3 ;
                // temp3.code = NULL;
                temp3.left = temp1;
                temp3.right = temp2;
                temp3.letter = ' ';
                temp3.probility = temp1->probility + temp2->probility;
                insertMinHeap(p,&temp3);
        }
        return extractMinELe(p);
}

huffmanCodeArray genHuffmanCodes(const  node* p,int n){
        int tempLen = 0;   // 描述编码的长度
        char * tempStorage = (char*) malloc(sizeof(char) * n);
 
        // int tempStackLen = 0 ;     // 描述栈的长度
        // node ** tempStack = (node**) malloc(sizeof(node*)*n);
        // tempStack[tempStackLen++] = p;
       
        huffmanCodeArray hca;
        hca.len = 0;
        hca.array = (huffmanCode*) malloc(sizeof(huffmanCode)*n);
        makeCode(p,tempStorage,tempLen,&hca)  ; // call

        // 释放 tempStorage;
        //printf("In genHuffmanCodes %ld\n",tempStorage);
        free(tempStorage);
         //  释放 哈夫曼树
        freeNodes(p,n);
        return hca;
}

void makeCode(const node*p, char * tempStorage,int tempLen,huffmanCodeArray*hca){
         if(p->left != NULL){
                tempStorage[tempLen++] = '0' ;
                makeCode(p->left,tempStorage,tempLen,hca);
                // 此处不再判断右孩子是否空孩子，因为一个节点如果有孩子那么肯定是有两个孩子
                tempStorage[tempLen-1] ='1';
                makeCode(p->right,tempStorage,tempLen,hca);
        }
        else{  //叶子
                
                hca->array[hca->len].letter = p->letter;
                hca->array[hca->len].code = (char*)malloc((tempLen+1)*sizeof(char));
                strncpy(hca->array[hca->len].code,tempStorage,tempLen);
                hca->array[hca->len].code [tempLen]='\0';
                hca->len++;
        }
}

huffmanCodeArray pure2HuffmanCodes(nodeArray* p){
        /*copy from the p , we should't change the input parametors*/
        nodeArray copy;         // copy 是一个堆
        copy.array= (node*)malloc((p->len+1)*sizeof(node));
        copy.len = p->len;
        for(int temp = p->len;temp >= 1;temp--){
                copy.array[temp] = p->array[temp];
        }
        buildMinHeap(&copy);
        node root = buildHuffmanTree(&copy);
        // 释放 copy.array
        //printf("In pure2HuffmanCodes, free  %ld\n",copy.array);
        free(copy.array);

        // root points to the stack space, but it's children point to heap space (dynamic) 
       return genHuffmanCodes(&root,p->len);
}
