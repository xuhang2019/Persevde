#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> result;
vector<int> path;

void dfs(int n, vector<bool> &used){
    if(n == path.size()){
        result.push_back(path);
        return;
    }

    for(int i = 1; i<=n ; i++){
        if(used[i] == true) continue;
        path.push_back(i);
        used[i] = true;
        dfs(n, used);
        path.pop_back();
        used[i] = false;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    vector<bool> used(n+1, false);
    
    dfs(n, used);

    for(int i = 0; i< result.size(); i++){
        for(int j=0; j<result[0].size() - 1; j++){
            printf("%d ", result[i][j]);
        }
        printf("%d\n", result[i][result[0].size() - 1]);
    }

}