#include<cstdio>
#include<algorithm>

using namespace std;

const int N =  1007;
int dad[N];
bool isroot[N];

// delicate design of union-find-set:
// findfather and uniontwo
int finddad(int x){
    return x;

    // compress paths
}

void uniondad(int a, int b){
    dad[finddad(a)] = finddad(b);
}

// initialize global paras
void init(int n){
    for(int i = 0; i<n;i++){
        isroot[i] = false;
        dad[i] = i;
    }
}

int main(){
    int n;
    int res = 0;

    // read two elements
    // union

    for(int i = 0;i < n; i++){
        res += isroot[finddad(i)];
    }
    printf("%d\n",res);
}