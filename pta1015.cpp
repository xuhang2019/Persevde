#include <iostream>
using namespace std;

// 写一个对数组排序并且记录下索引的函数，这样就可以通过索引去返回指定的值。

void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


void BubbleSort(int *p,int length,int *index,int flag){
    // flag = 1升序，flag = -1 降序
    // for(int i = 0;i<length;i++){index[i] = i;} // 初始化 index数组
    for(int i = 0;i<length;i++){
        for(int j = 0;j<length - i - 1;j++){
            if(flag == -1){
                if(p[j] < p[j+1]){
                swap(&p[j],&p[j+1]);
                swap(&index[j],&index[j+1]);
                }
            }
            else if(flag == 1){
                if(p[j] > p[j+1]){
                swap(&p[j],&p[j+1]);
                swap(&index[j],&index[j+1]);
                }
            }
            
        }
    }
}


int main(){

    int N,L,H;
    int tmp_zkz,tmp_de,tmp_cai;
    //四类 1.>=H 2.de>=H 3.de>=cai 4.others
    int zkz1[10100],de1[10100],cai1[10100],sum1[10100];
    int zkz2[10100],de2[10100],cai2[10100],sum2[10100];
    int zkz3[10100],de3[10100],cai3[10100],sum3[10100];
    int zkz4[10100],de4[10100],cai4[10100],sum4[10100];
    int length[10100];
    int cnt = 0; // 通过的总数
    int inx1 = 0,inx2 = 0,inx3 = 0,inx4 = 0;

    while(cin >> N >> L >> H){
        for(int i = 0;i<N;i++){
            cin >> tmp_zkz >> tmp_de >> tmp_cai;
            if(tmp_de<L && tmp_cai < L) continue;
            else if(tmp_de>= H && tmp_cai >=H){
                zkz1[inx1++] = tmp_zkz;
                de1[inx1++] = tmp_de;
                cai1[inx1++] = tmp_cai;
                sum1[inx1++] = tmp_de+tmp_cai; 
            }
            else if(tmp_de >= H){
                zkz2[inx2++] = tmp_zkz;
                de2[inx2++] = tmp_de;
                cai2[inx2++] = tmp_cai;
                sum2[inx2++] = tmp_de+tmp_cai; 
            }
            else if(tmp_de >= tmp_cai){
                zkz3[inx3++] = tmp_zkz;
                de3[inx3++] = tmp_de;
                cai3[inx3++] = tmp_cai;
                sum3[inx3++] = tmp_de+tmp_cai; 
            }
            else{
                zkz4[inx4++] = tmp_zkz;
                de4[inx4++] = tmp_de;
                cai4[inx4++] = tmp_cai;
                sum4[inx4++] = tmp_de+tmp_cai; 
            }

            cnt ++;
        }
    }

    cout << cnt << endl;
    // 处理完IO流，接下来按照sum排序即可
    for(int ii = 0;ii<inx1;ii++){
        length[ii] = ii;
    }
    
    BubbleSort(zkz1,inx1,length,1);
    BubbleSort(de1,inx1,length,-1);
    BubbleSort(sum1,inx1,length,-1);
    for(int i = 0;i<inx1;i++){
        printf("%d %d %d",zkz1[length[i]],de1[length[i]],cai1[length[i]]);
    }
    
    
}