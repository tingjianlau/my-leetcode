/*************************************************************************
	> File Name: 344_reverse_string.c
	> Author: Tingjian Lau
	> Mail: tjliu@mail.ustc.edu.cn
	> Created Time: 2016/05/10
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseString_1(char *s){
    int len, i;
    char *str;

    len = strlen(s);
    if(len == 0) return " ";
    str = (char*)malloc(sizeof(char)*len);
    for(i = 0; i < len; i++){
        str[i] = s[len - i - 1];
    }

    return str;
}

int main(){
    printf("%s\n", reverseString_1("abcdef"));

    return 0;
}
