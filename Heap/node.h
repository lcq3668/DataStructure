#ifndef  NODE_H
#define NODE_H
struct node{
    double probility;
    struct node* left;
    struct node* right;
    // char * code;
    char letter; 
};
typedef struct node node;
struct nodeArray{
    node * array;
    int len;
};

typedef struct nodeArray nodeArray;
#endif