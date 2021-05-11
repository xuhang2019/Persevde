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
    for(int i = 0;i<n;i++){
        ind ++;
        seq[ind] = find_link(now_add,l,n);
        now_add = l[ind].next_add;
        if(now_add == -1) break;
    }

    for(int i = k-1;i>=0;i--){
        printf("%05d %d %05d\n",l[seq[i]].add,l[seq[i]].data,l[seq[i]].next_add);
    }
    for(int i = k;i<=ind;i++){
        printf("%05d %d %05d\n",l[seq[i]].add,l[seq[i]].data,l[seq[i]].next_add);
    }

}