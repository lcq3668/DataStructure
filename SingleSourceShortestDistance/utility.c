#include"utility.h"
#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
repo readFIle(const char * fileName){
        FILE* fp = fopen(fileName, "r"); 
        long int res ;
         char * p;
         repo  r;
        if (fp == NULL) { 
                printf("File Not Found!\n"); 
               exit(0); 
        } 
       fseek(fp, 0L, SEEK_END); 
  
    // calculating the size of the file 
        res  = ftell(fp); 
        p = (char *)malloc(sizeof(char)*(res+1));
        p[res]='\0';
        r.n = res;
        fseek(fp, 0L, SEEK_SET); 
        while(res>0){
                size_t n = fread(p + (r.n - res),sizeof(char) ,res,fp);  
                res -= n;
        }
        r.rawContent = p;
        fclose(fp);
        return r;
}

weightMatrix  genMatrix(repo r){
        /* 文本数据的第一行是 点的个数*/
        long int  i;
        int n;
        for(i = 0; i< r.n;i++){
            if(r.rawContent[i] <'0' ||  r.rawContent[i] >'9'){
                    
                    r.rawContent[i] = '\0';
                    break;
            }   
        }
        n = atoi(r.rawContent);
        if(n<=0){
                printf("The a mount of node is less or equal to 0. It's illegal\n");
                exit(0);
        }
        double * weights =  (double*)malloc(sizeof(double) * n *n);
        // r.rawContent[i] !='-' || r.rawContent[i] !='+' ||  r.rawContent[i] !='.' ||
        int counter = 0;
        for(int j = ++i; i< r.n;i++){
            while(i< r.n&& (r.rawContent[i] !='-' && r.rawContent[i] !='+' && r.rawContent[i] !='.'&&(r.rawContent[i] <'0' ||  r.rawContent[i] >'9'))){
                    i++;
            }
            if(i == r.n){
                    break;
            }
            j = i;
            //printf("j is %d\n",j);
            i++;
            while(i< r.n&& (r.rawContent[i] =='-' || r.rawContent[i] =='+' || r.rawContent[i] =='.'||(r.rawContent[i] >='0' && r.rawContent[i] <='9'))){
                    
                   i++;
            }  

            
            r.rawContent[i] = '\0';
            
            weights[counter]=atof(r.rawContent+j) ;
            if(weights[counter] == -1.0){
                    weights[counter]  = (double)INT_MAX ;
            }
            counter++;

        }
        if(counter != (n*n)){
               printf("The size of weight matrix is %d. It's wrong\n",counter);
                exit(0);

        }
        weightMatrix wm;
        wm.weights = weights;
        wm.n = n;
        return  wm;
}

weightList genList(weightMatrix matrix){
        node** vertex = (node**)malloc(sizeof(node*)*matrix.n);
        int n = matrix.n;
        node* follower;
        for(int i = 0; i<n; i++){
                vertex[i] = NULL;
        }
        for(int i = 0;i<n;i++){
                for(int j = 0; j<n;j++){
                        if(matrix.weights[i*n+j] != (double)INT_MAX &&  matrix.weights[i*n+j] != (double)0.0){
                                node* tempNode = (node*)malloc(sizeof(node));
                                tempNode->weight = matrix.weights[i*n+j] ;
                                tempNode->v = j;
                                if(vertex[i] == NULL){
                                        vertex[i] = tempNode;
                                        follower = tempNode;
                                        follower->next = NULL;
                                }
                                else{
                                        follower->next = tempNode;
                                        follower = tempNode;
                                        follower->next = NULL;
                                }
                               
                        }
                }
               
        }
        weightList wl;
        wl.n = matrix.n;
        wl.vertex = vertex;
        return wl;

}


