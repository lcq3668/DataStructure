#ifndef HUFFMANCODE_H
#define  HUFFMANCODE_H
struct huffmanCode{
        char *code;
        char letter;
};
typedef struct huffmanCode huffmanCode;
struct huffmanCodeArray{
        huffmanCode* array;
        int len;
};
typedef struct huffmanCodeArray huffmanCodeArray;
#endif