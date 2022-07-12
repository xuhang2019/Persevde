#include<cstdio>
#include<algorithm>

using namespace std;

struct node{
    int data;
    node* lchild, *rchild;
};

node* root = NULL; // 地址是NULL，而不是内容是NULL。

node* newNode(int v){
    node* n = new node; // new 和 malloc一样都是要地址。
    n->data = v;
    n->lchild = n->rchild = NULL;
    return n;
}

node* a = newNode(5);


int main(){
    node *b = newNode(1); // 千万别 root -> lchild, root可没有地址
    b->lchild = a;
    return 0;
}