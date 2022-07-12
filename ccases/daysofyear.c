#include <stdio.h>

int month[2][13] = {
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int dayofyear(int y,int m, int d){
    int is_leap=0;
    int days = 0;
    is_leap = (y%4 == 0)&&(y%100 != 0 || y%400 == 0)? 1: 0;
    for(int i = 1; i<m;i++){
        days += month[is_leap][i];
    }
    days += d;
    return days;
}

int main(){

    int y,m,d;
    scanf("%d:%d:%d",&y,&m,&d);
    printf("%d",dayofyear(y,m,d));
    return 0;

}