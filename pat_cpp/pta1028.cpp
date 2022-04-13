//
// Created by xuhang on 2021/5/14.
// 难点主要在于分隔字符串，真的精细活。
// 这题告诉我们sort_cmp不仅可以用来放入sort做cmp函数，还可以方便地给出数组里最大值最小值，而且是纯IO流处理。
//
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct ren{
    string name;
    int year;
    int month;
    int day;
};

bool judge(int y,int m,int d){
    // 大于200岁
    bool cond1  = y<1814;
    bool cond2  = (y == 1814)&&(m<9);
    bool cond3 = (y == 1814) && (m == 9) &&(d < 6);

    //小于当前日子
    bool cond4  = y>2014;
    bool cond5  = (y == 2014)&&(m>9);
    bool cond6 = (y == 2014) && (m == 9) &&(d > 6);

    if(cond1 || cond2 || cond3 || cond4 || cond5 ||cond6) return false;
    else return true;
}

bool sort_cmp(ren r1,ren r2){
    if(r1.year < r2.year) return true;
    else if(r1.year == r2.year && r1.month < r2.month) return true;
    else if(r1.year == r2.year && r1.month == r2.month && r1.day < r2.day) return true;
    else return false;
}

int main(){
    int n; // 题目输入数据
    int inx = 0; // 长度，指向的是有效数组的后一位。
    ren r[100100];
    string now_name;
    int now_year;
    int now_month;
    int now_day;
    int old_inx = 0;
    int young_inx = 0;


    while(cin >> n){
        for(int i = 0;i<n;i++){
            cin >> now_name;
            scanf("%d/%d/%d",&now_year,&now_month,&now_day);
            if(judge(now_year,now_month,now_day)){
                r[inx].name = now_name;
                r[inx].year = now_year;
                r[inx].month = now_month;
                r[inx].day = now_day;
                if(sort_cmp(r[young_inx],r[inx])) young_inx = inx;
                if(sort_cmp(r[inx],r[old_inx])) old_inx = inx;
                inx ++ ;
            }
        }
    }
    if(inx == 0) cout << 0 <<  endl;
    else cout <<inx<< ' ' << r[old_inx].name << ' ' << r[young_inx].name << endl;
}