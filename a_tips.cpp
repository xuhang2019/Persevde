#include <iostream>

using namespace std;

 inline void read(int &x)
 {
     char ch = getchar(), c = ch;
     while(ch < ' ' || ch > ' ')c = ch, ch = getchar();
     while(ch <= ' ' && ch >= ' ')x = x *  + ch - ' ', ch = getchar();
     if(c == '-')x = -x;
 }
 

// gcd 写法 相当于是分治
int gcd(int a,int b){
    return b == 0? a : gcd(b,a%b);
}

int main(){
    cout << gcd(5,10) << gcd(10,5) << endl;
}

