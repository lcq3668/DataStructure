#include<string.h>
#include"LPS.h"
#include<stdlib.h>
#define False '0'
#define True '1'
char * longestPalindrome(char * s){
    int lenStr = strlen(s);
    char * isPalindrome = (char *)malloc(sizeof(char)* lenStr * lenStr);
    for(int i = 0;i < lenStr; i++){
        isPalindrome[ i * lenStr + i] = True;
    }
    for(int i = 0; i +1 < lenStr; i++){
       
        isPalindrome[ i * lenStr + (i+1)] = (s[i] == s[i+1]?True:False);
        
    }
    for(int end = lenStr -1 , step = 2; step <= end; step++ ){
        for(int i = 0 ,j = i + step; j < lenStr; i++,j++){
            if(s[i] == s[j] && isPalindrome[(i+1) * lenStr + (j-1)] == True){
                isPalindrome[i * lenStr + j] = True;
            }
            else{
                isPalindrome[i * lenStr + j] = False;
            }
        }
    }
    for(int step = lenStr -1; step>=1;step--){
        for(int i = 0 ,j = i + step; j < lenStr; i++,j++){
            if(isPalindrome[i * lenStr + j] == True){
                free(isPalindrome);
                return buildSubStr(s,i,j);
            }
                
        }
    }
    free(isPalindrome);
    return buildSubStr(s,0,0);

}

char* buildSubStr(const char * s,int left ,int right){
    char * ans = (char*)malloc(sizeof(char) * (right - left +2));
    strncpy(ans,s + left ,right - left +1);
    ans[right - left +1]='\0';
    return ans;
}