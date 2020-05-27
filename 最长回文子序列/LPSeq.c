#include<string.h>
#include<stdlib.h>
#include"LPSeq.h"
int longestPalindromeSubseq(char * s){
    int lenStr = strlen(s);
    int * lenSub = (int*)malloc(sizeof(int) * lenStr * lenStr);
    int ans;
    for(int i = 0 ; i < lenStr ; i++){
        lenSub[ i * lenStr + i] = 1 ;
    }
    for(int i = 0 ; i +1< lenStr ; i++){
        if(s[i] == s[i+1])
            lenSub[ i * lenStr + (i+1)] = 2 ;
        else
            lenSub[ i * lenStr + (i+1)] = 1 ;
    }
    for(int step = lenStr -1 ,k = 2; k <= step;k++){
        for(int i = 0 , j = i+k; j < lenStr;i++,j++){
            if(s[i] == s[j]){
                lenSub[ i * lenStr + j] = lenSub[ (i+1) * lenStr + (j-1)] + 2 ;
            }
            else{
                if(lenSub[ i * lenStr + (j-1)] >= lenSub[ (i+1) * lenStr + j]){
                    lenSub[ i * lenStr + j] = lenSub[ i * lenStr + (j-1)];
                }
                else{
                    lenSub[ i * lenStr + j] = lenSub[ (i+1) * lenStr + j];
                }
            }
        }
    }
    ans = lenSub[lenStr -1];
    free(lenSub);
    return ans;
}