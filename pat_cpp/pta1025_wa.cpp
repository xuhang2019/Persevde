#include <iostream>

using namespace std;

struct link{
    int add;
    int data;
    int next_add;
};

int find_link(int add, link* l, int len){
    for(int i = 0;i<len;i++){
        if(l[i].add == add) return i;
    }
    return -1;

}

int main(){
    int first_add,n,k;
    int first_seq;
    int now_add;
    int ind = 0;
    int seq[100100];
    link l[100100];
    while(cin >> first_add >> n >> k){
        for(int i = 0;i<n;i++){
            cin >> l[i].add >> l[i].data >> l[i].next_add;
            if(l[i].add == first_add) first_seq = i;
        }
    }

    seq[ind] = first_seq;
    now_add = l[first_seq].next_add;

    // 搜索整个链表 最后一个链表的地址放在seq[ind] 完整链表的长度 ind
    for(int i = 0;i<n;i++){
        ind ++;
        seq[ind] = find_link(now_add,l,n);
        now_add = l[seq[ind]].next_add;
        if(now_add == -1) break;
    }

    for(int i = k-1;i>=0;i--){
        // 用来处理 链表的next_add绑定和完全反转链表的操作。
        if(i!=0) l[seq[i]].next_add = l[seq[i-1]].add;
        else if(k<=ind) l[seq[i]].next_add = l[seq[k]].add;
        else if(k > ind) l[seq[i]].next_add = -1;

        if(l[seq[i]].next_add!=-1) printf("%05d %d %05d\n",l[seq[i]].add,l[seq[i]].data,l[seq[i]].next_add);
        else printf("%05d %d -1\n",l[seq[i]].add,l[seq[i]].data,l[seq[i]].next_add);
    }
    for(int i = k;i<=ind;i++){
        if(l[seq[i]].next_add != -1){
            l[seq[i]].next_add = l[seq[i+1]].add;
            printf("%05d %d %05d\n",l[seq[i]].add,l[seq[i]].data,l[seq[i]].next_add);
        }
        else{
            printf("%05d %d -1\n",l[seq[i]].add,l[seq[i]].data);
        }

    }

}