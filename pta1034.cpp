#include<iostream>

using namespace std;

// abstract到位，有理数的核心思路是除法，无论是最后的结果还是一开始的输入

long long gcd(long long a,long long b){
    return b == 0? a : gcd(b,a%b);
}

bool nega(long long &a,long long &b){
    int flag = 0;
    if(a<0){
        flag += 1;
        a = -a;
    }
    if(b<0){
        flag += 1;
        b = -b;
    }
    return (flag%2 != 0);
}

// 负责处理输入a,b之后显示的数
// 1.直接除 2.假分数 3.负数 4. Inf 5.整数
void func(long long a, long long b){
    if(b == 0){
        cout << "Inf";
        return;
    }
    if(a == 0){
        cout << 0;
        return;
    }
    bool neg = nega(a,b);
    if(neg) cout<<"(-";
    long long c = gcd(a,b);
    a /= c; b/= c;
    if(b == 1) cout << a;
    else if(a > b){
        int zs = a/b;
        int fz = a%b;
        cout << zs <<' '<< fz << "/" << b;
    }
    else if(a<b){
        cout << a << "/" << b;
    }
    if(neg) cout << ")";
}


int main(){
    long long a1,b1,a2,b2;
    scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2);
    func(a1,b1);cout << " + ";func(a2,b2);cout << " = ";func(a1*b2+a2*b1,b1*b2);cout<< endl;
    func(a1,b1);cout << " - ";func(a2,b2);cout << " = ";func(a1*b2-a2*b1,b1*b2);cout<< endl;
    func(a1,b1);cout << " * ";func(a2,b2);cout << " = ";func(a1*a2,b1*b2);cout<< endl;
    func(a1,b1);cout << " / ";func(a2,b2);cout << " = ";func(a1*b2,a2*b1);cout<< endl;  
}