#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> result;
vector<int> path;

void dfs(int n, int k, int startIndex){
    if(path.size() == k){
        result.push_back(path);
        return;
    }

    for(int i = startIndex; i<=n; i++){
        path.push_back(i);
        dfs(n, k, i+1);
        path.pop_back(); // back to the previous node 
    }
}

int main(){
    int n,k;
    int startIndex;
    scanf("%d %d",&n,&k);
    dfs(n, k, 1);
    for(int i = 0; i< result.size(); i++){
        for(int j=0; j<result[0].size() - 1; j++){
            printf("%d ", result[i][j]);
        }
        printf("%d\n", result[i][result[0].size() - 1]);
    }
}