#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1000;
int n = 5, V = 8;
int w[N] = {3, 5, 1, 2, 2}, c[N] = {4, 5, 2, 1, 3};
int maxC = 0;

int cnt = 0;

void dfs(int index, int sumW, int sumC)
{
    cnt ++;
    // 这里很关键，什么时候return 代表dfs终止。 sumW > V能终止吗？还没dfs到最深处。
    if (index == n || sumW > V){
        if (sumC > maxC && sumW <= V){
            maxC = sumC;
        }
        return;
    }

    // if(index == n){
    //     if(sumC > maxC && sumW <= V){
    //         maxC = sumC;
    //     }
    //     return;
    // }

    // if(index == n) return;

    dfs(index + 1, sumW, sumC);
    dfs(index + 1, sumW + w[index], sumC + c[index]);


    // 在进入分支之前就加入判断，是剪枝操作。 cnt次数更少。
    // if(sumW + w[index] <= V){
    //     if(sumC + c[index] > maxC){
    //         maxC = sumC + c[index];
    //     }
    //     dfs(index + 1, sumW + w[index], sumC + c[index]);
    // }
    
}

int main()
{
    dfs(0, 0, 0);
    printf("%d\n", maxC);
    printf("cnt: %d\n", cnt);
    return 0;
}