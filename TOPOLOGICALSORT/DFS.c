#include"DFS.h"
#include<stdlib.h>
#include<stdio.h>
vertex** DFS(Graph g){
        int * visited = (int*)malloc(sizeof(int)*g.n);
         if(visited == NULL){
                printf("malloc failed in visited\n");
                exit(0);
        }
        sequence se;
        se.n = 0;
        se.vp = (vertex**)malloc(sizeof(vertex*)*g.n);
        if(se.vp == NULL){
                printf("malloc failed in se\n");
                exit(0);
        }
        int time = 0;
        for(int i = 0; i<g.n; i++){
            visited[i] = 0;
        }

        for(int i = 0; i<g.n;i++){
                if(!visited[i]){
                    DFSVisit(g.vs+i,visited,&time,&se);
                }
        }
        free(visited);
        return se.vp;
}

void DFSVisit(vertex* v, int * visited,int* time,sequence* sq){
        visited[v->self] = 1;
        v->s = *time;
        (*time)++;
        vertex*temp = v->next;
        while(temp != NULL){
                if(!visited[temp->self]){
                    
                        DFSVisit(v+(temp->self -  v->self),visited,time,sq);
                }
                temp = temp->next;
        }
        v->f = *time;
        (*time)++;
        sq->vp[sq->n++] = v;
}