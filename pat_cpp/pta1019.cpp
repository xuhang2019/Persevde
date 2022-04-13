//
// Created by xuhang on 2021/5/8.
//
#include <iostream>
#include <algorithm>

using namespace std;
void process(int num,int *dig){

    for(int i= 0;i<4;i++){
        dig[3-i] = (num%10);
        num /= 10;
    }
    sort(dig,dig+4);
}

int main(){
    int num;
    int dig[4];
    int weight = 1;
    int big = 0,lit = 0;
    int delta  = 0;
    cin >> num;

    process(num,dig);
    for(int i = 0;i<4;i++){
        big += weight*dig[i];
        lit += weight*dig[3-i];
        weight*= 10;
    }
    // cout <<  big <<  lit;
    delta = big-lit;
    printf("%04d - %04d = %04d\n",big,lit,delta);
    if(delta == 0|| delta == 6174){
        return 0;
    }
    while(delta != 6174){
        // 这样写说明耦合度还不够高，还有更优的写法
        // 记得把这些局部变量初始化
        big = 0;
        lit = 0;
        weight = 1;
        process(delta,dig);
        for(int i = 0;i<4;i++){
            big += weight*dig[i];
            lit += weight*dig[3-i];
            weight*= 10;
        }
        delta = big - lit;
        printf("%04d - %04d = %04d\n",big,lit,delta);
    }
    return 0;
}