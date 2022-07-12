#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100007;

struct Node{
    int add, next; // add 可以省略
    char data;
    bool flag;
    Node(): add(), data(), next() {} // 必须加一个这个，否则 node[N] 直接报错；必须使用构造函数。
    Node(int _add, char _data, int _next): add(_add), data(_data), next(_next) {} // 会覆盖原有的空白构造函数
} node[N];

int main(){

    // data area
    int n = 9, s1 = 11111, s2 = 22222;
    node[67890] = {67890, 'i', 00002};
    node[00010] = {00010, 'a', 12345};
    node[00003] = {00003, 'g', -1};
    node[12345] = {12345, 'D', 67890};
    node[00002] = {00002, 'n', 00003};
    node[22222] = {22222, 'B', 23456};
    node[11111] = {11111, 'L', 00001};
    node[23456] = {23456, 'e', 67890};
    node[00001] = {00001, 'o', 00010};

    // process static list
    for(int i = 0; i< N;i ++) node[i].flag = false;
    int p = s1;
    
    while(p != -1){
        node[p].flag = true;
        p = node[p].next;
    }

    p = s2;
    while(p != -1){
        if(node[p].flag == true){
            printf("%d\n",p);
            return 0;
        }
        p = node[p].next;
    }
    printf("-1\n");

    return 0;

}