#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100007;

struct Node{
    int add, data, next;
    bool flag;
    Node(): add(), data(), next() {} // 必须加一个这个，否则 node[N] 直接报错；必须使用构造函数。
    Node(int _add, int _data, int _next): add(_add), data(_data), next(_next) {} // 会覆盖原有的空白构造函数
} node[N];

bool cmp(Node a, Node b){
    if(a.flag == false || b.flag == false){
        return a.flag > b.flag;
    }
    else{
        return a.data < b.data;
    }
}

int main(){

    // data area
    int n = 6, begin = 00001;
    node[11111] = {11111, 100, -1};
    node[00001] = {00001, 0, 22222};
    node[33333] = {33333, 100000, 11111};
    node[12345] = {12345, -1, 33333};
    node[22222] = {22222, 1000, 12345};
    node[10909] = {10909, 9999999, 34325};

    // process static list
    for(int i = 0; i< N;i ++) node[i].flag = false;
    int p = begin, cnt = 0;
    
    while(p != -1){
        node[p].flag = true;
        cnt ++;
        p = node[p].next;
    }

    sort(node, node+N, cmp);
    
    if(0 == cnt) printf("0 -1\n");
    else{
        printf("%d %05d\n",cnt, node[0].add);
        for(int i = 0; i< cnt; i++){
            if(i < cnt - 1){
                printf("%05d %d %05d\n",node[i].add, node[i].data, node[i+1].add);
            }
            else{
                printf("%05d %d -1\n",node[i].add, node[i].data);
            }
        }
    }

    return 0;

}