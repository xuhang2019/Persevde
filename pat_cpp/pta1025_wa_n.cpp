#include <iostream>

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
for(int i = 0;i<ind;i++){cout << seq[i]<<endl;}
    for(int i = k-1;i>=0;i--){
        // 用来处理 链表的next_add绑定和完全反转链表的操作。

        // 这里有逻辑问题。 i!=0 处理的是seq[0]之前的next_add绑定
        // k <= ind 反转的数小于总的数 k =6 ind = 6(7个)
        // k > ind ,k = ind+1 ，相当于完全反转，那end = Null
        if(i!=0) l[seq[i]].next_add = seq[i-1];
        // i = 0；
        else if(k<=ind) l[seq[i]].next_add = seq[k];
        else if(k > ind) l[seq[i]].next_add = -1;

        if(l[seq[i]].next_add!=-1) printf("%05d %d %05d\n",seq[i],l[seq[i]].data,l[seq[i]].next_add);
        else printf("%05d %d -1\n",seq[i],l[seq[i]].data);
    }
    for(int i = k;i<=ind;i++){
        if(l[seq[i]].next_add != -1){
            l[seq[i]].next_add = seq[i+1];
            printf("%05d %d %05d\n",seq[i],l[seq[i]].data,l[seq[i]].next_add);
        }
        else{
            printf("%05d %d -1\n",seq[i],l[seq[i]].data);
        }

    }
}