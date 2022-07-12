#include <stdio.h>

int main(){

    int a = 0x01020304;
    char *c = (char *)&a; // 这个强制类型转换写的非常不错
    if(0x04 == *c) printf("little endian");
    else printf("big endian");

}