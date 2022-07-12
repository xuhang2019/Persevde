#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1000;
const int INF = 0x3FFFFFFF;
int G[N][N];
int d[N]; // 最短距离。
bool visit[N] = {false}; // 访问节点标记。

int n = 10;

void dijkstra(int s){
    fill(d, d+n, INF);
    d[s] = 0;
    for(int i = 0; i<n; i++){
        int u = -1, MIN = INF;
        for(int j = 0; j<n; j++){
            if(d[j] < INF && visit[j] == false){ // d[s] = 0, 所以第一次循环出来的肯定是d[s]
                u = j;
                MIN = d[j];
            }
        }
        if(-1 == u) return; // 无连通;
        visit[u] = true; // V (all nodes) - S (min node set)

        for(int j = 0; j < n; j++){
            if(visit[j] == false && G[u][j]!= INF && d[u] + G[u][j] < d[j]){
                d[j] = d[u] + G[u][j];
            }
        }
    }
}

int main(){
    dijkstra(0);
    return d[n];
}
