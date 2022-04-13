//
// Created by xuhang on 2021/5/15.
//

#include <iostream>
#include <algorithm>

using namespace std;

struct link2{
    int data;
    int next_add;
};

int main(){
    int first_add,n,k;
    int ind = 0;
    int seq[100100];
    int now_add = 0;
    link2 l[100100];
    while(cin >> first_add >> n >> k){
        for(int i = 0;i<n;i++){
            cin >> now_add >> l[now_add].data >> l[now_add].next_add;
        }
    }

    seq[ind] = first_add;
    // 搜索整个链表 最后一个链表的地址放在seq[ind] 完整链表的长度 ind
    for(int i = 0;i<n;i++){
        now_add = l[seq[ind]].next_add;
        if(now_add == -1) break;
        ind ++;
        seq[ind] = now_add;
    }

    for(int i = 0;i< ((ind+1) - (ind+1) % k); i += k) // 每k个反转
        reverse(begin(seq) + i, begin(seq) + i + k);

    for(int i = 0;i<ind;i ++)
        printf("%05d %d %05d\n",seq[i],l[seq[i]].data,seq[i+1]);
    printf("%05d %d -1\n",seq[ind],l[seq[ind]].data);

}