//
// Created by xuhang on 2021/5/8.
// 测试点3 输入0，输出0
//

#include <iostream>
#include <string>
using namespace std;

// 123 + 456 = 579 8
// 579%8 =
int result[40]={0};

int trans(int n,long int sum){

    int i = 0;
    while(sum!=0){
        result[i++] = sum%n;
        sum /= n;
    }
    return i;
}

int main(){
    long int a,b;
    long int sum;
    int n,length;
    cin>>a>>b>>n;
    sum = a+b;
    if(sum == 0){
        cout<< 0;
        return 0;
    }
    length = trans(n,sum);
    for(int i = length-1;i>=0;i--){
        cout<<result[i];
    }

}
