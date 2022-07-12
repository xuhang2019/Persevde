/*
    我感觉更多是回溯算法。
    处理一个分支的时候，载入tmp。
    处理完分支之后，pop_back出来，使其结果不影响另一分支。
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1000;
vector<int> tmp, result;
vector<bool> used(N,false);

int num[N] = {2,5,6,7,8,9};
int n = 6,k = 2,x = 13;
int maxsum2 = 0;

void dfs(int index, int sum, int sum2){
    if(k == tmp.size() || index == n){ // choose k items
        if(sum == x){
            if(sum2 > maxsum2){
                maxsum2 = sum2;
                result = tmp;
            }
        } 
        return;
    }
    // 不选 index
    dfs(index + 1, sum, sum2);

    // 选 index
    // used[index] = true;
    tmp.push_back(num[index]);
    dfs(index + 1, sum + num[index], sum2 + num[index]*num[index]);
    // used[index] = false;
    tmp.pop_back();
}

int main(){
    dfs(0, 0, 0);
    for(int i = 0; i< k; i++){
        printf("%d ", result[i]);
    }
    return 0;
}