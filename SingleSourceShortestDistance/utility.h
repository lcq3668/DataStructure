#ifndef UTILITY_H
#define UTILITY_H
struct repo{
        char * rawContent;
        long int n;
}; 
typedef struct repo repo;
struct node{
        double weight;
        struct node* next;
        int v;
};
typedef struct node node;
struct weightMatrix{
        double * weights;
        int n;
};
typedef  struct weightMatrix weightMatrix;

struct weightList{
        node ** vertex;
        int n;
};
typedef struct weightList weightList;

repo readFIle(const char * fileName);
weightMatrix  genMatrix(repo r);
weightList   genList(weightMatrix   matrix);
#endif