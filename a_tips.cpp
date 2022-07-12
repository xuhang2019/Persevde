#include <iostream>

using namespace std;

// gcd 写法 相当于是分治
int gcd(int a,int b){
    return b == 0? a : gcd(b,a%b);
}

int main(){
    cout << gcd(5,10) << gcd(10,5) << endl;
}