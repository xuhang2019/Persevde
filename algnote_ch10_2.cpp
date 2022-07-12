/*
对于图的遍历核心在于 遍历连通块。
访问每个未被访问过（visit[i] = false）的节点，去依次遍历其中的连通块。
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1000;
const int INF = 1000000000;
int G[N][N];
vector<int> Adj[N];

bool visit[N] = {false};

int n; // number of nodes

void dfs_G(int u, int depth){
    visit[u] = true;
    for(int i = 0;i < n; i++){
        if(visit[i] == false && G[u][i] != INF){
            dfs_G(i, depth+1); // 遍历连通块
        }
    }
}

void dfs_Adj(int u, int depth){
    visit[u] = true;
    for(int i = 0;i < Adj[u].size(); i++){
        int tmp = Adj[u][i];
        if(visit[i] == false && tmp != INF){
            dfs_Adj(i, depth+1);
        }
    }
}


void dfs_trave(){
    for(int i = 0;i < n; i++){
        if(visit[i] == false){
            dfs_G(i, 1);
            dfs_Adj(i, 1);
        }
    }
}

int main(){
    return 0;
}