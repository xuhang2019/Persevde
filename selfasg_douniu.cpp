/*
    斗个牛而已，用回溯总想回溯。
    其实 O(n^3) 复杂度 3重 for 就行。

    没有解决的问题：
        回溯剪枝/ dfs剪枝，运算效率太低。 得出结果无法快速退出递归循环。
*/


#include<cstdio>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> pei;
vector<bool> visited(5, false);
vector<int> res;
char num[5];

void cal_niu(int start){
    if(pei.size() == 3){
        if((pei[0] + pei[1] + pei[2])%10 == 0){
            int ans = 0;
            for(int j = 0; j< 5; j++){
                if(!visited[j]){
                    ans = (ans + num[j])%10;
                }
            }
            res.push_back(ans);
        }
        return;
    }
    for(int i = start; i< 5; i++){
        pei.push_back(num[i]);
        visited[i] = true;
        cal_niu(start + 1);
        pei.pop_back();
        visited[i] = false;
    }
};

// O(n^3) 算法也行



int main(){

    // 不能这样处理， 这样无法处理 10
    // 感觉得 getchar(), 去计算空格
    scanf("%c %c %c %c %c",&num[0],&num[1],&num[2],&num[3],&num[4]); // 这里暂且认为 0 = 10;
    for(int i = 0;i < 5; i++){
        if(num[i] >= '1' && num[i] <= '9'){
            num[i] -= '0';
        }
        else{
            num[i] = 10;
        }
    }

    cal_niu(0);
    if(res.size() == 0){
        printf("无点");
    }
    else{
        printf("%d",res[0]);
    }
 
}