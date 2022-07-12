#include<iostream>
#include<string>

using namespace std;

int main(){
    string str;
    int weight[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    int Z_[] = {1,0,-1,9,8,7,6,5,4,3,2};
    int n;
    
    while(cin >> n){
        int all_pass_flag = 1;
        for(int i = 0;i<n;i++){
            cin >> str;
            int sum = 0;
            int flag2 = 0; // 数字退出
           
            for(int j = 0;j<17;j++){
                char ch = str[j];
                if(ch < '0' || ch > '9'){
                    all_pass_flag = 0;
                    flag2 = 1;
                    cout << str << endl;
                    break;
                }else{
                    sum += (ch-'0')*weight[j];
                }
            }
            if(flag2) continue;

            char z = str[17];
            int z_flag = Z_[sum%11];
            if(z_flag != -1){
                if(z != z_flag + '0'){
                    all_pass_flag = 0;
                    cout << str << endl;
                    continue;
                }
            }
            else{
                if((z != 'X')){
                    all_pass_flag = 0;
                    cout << str << endl;
                    continue;
                }
            }

            }
        if(all_pass_flag) cout << "All passed" << endl;
    }
}