//
// Created by xuhang on 2021/5/8.
//
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int big,lit;
void get_num(int n){
    int a[4];
    for (int i = 0; i < 4; i++) {
        a[i] = n % 10;
        n = n / 10;
    }
    sort(a, a + 4);
    big = 1000 * a[3] + 100 * a[2] + 10 * a[1] + a[0];
    lit = 1000 * a[0] + 100 * a[1] + 10 * a[2] + a[3];
}


int main(){
    // 1.高耦合的版本，之前需要定义big = 0,lit = 0，说明考虑不够周到，可以考虑直接定义为全局变量在函数中处理。
    //   这样做直接把big 和 lit放在函数中处理，每次直接生成big lit返回回来。 =》 见get_num()
    // cin >> n 这就不用说了，最基本的读取方法。

    /*
     * https://blog.csdn.net/qq_45677518/article/details/101560794
     * 这里通过 void(int ,int * ,int *)
     * 传& &地址进去，就可以实现改变变量的目的（代替返回值）
     */

    /*
     * 如果直接
     * string n;
     * cin >> n;
     * 也可以直接sort(n.begin(),n.end(),cmp1)
     * 再用
     * int max = stoi(n)
     * string to int 转换成int类型
     * to_string 转换成string类型
     */

}