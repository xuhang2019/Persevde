#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

struct Node{
        int v, w;
        Node(int _v, int _w): v(_v), w(_w) {}
};

const int N = 100;
vector<Node> Adj[N]; // vector<int, vector<int>> ?
/* vector is a container, Adj[N] creates N vectors. */


int main(){
    Adj[1].push_back(Node(3,4));
    Adj[1].push_back(Node(5,1));

    int a[N] = {1,2,3,4,5};

    // printf("Node 1:\n");
    // for(int i = 0; i< Adj[1].size(); i++){
    //     Node tmp = Adj[1][i];
    //     printf("v:%d w:%d\n",tmp.v, tmp.w);
    // }
}