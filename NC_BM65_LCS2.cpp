#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * longest common subsequence
     * @param s1 string字符串 the string
     * @param s2 string字符串 the string
     * @return string字符串
     */
    string LCS(string s1, string s2) {
        const int N = 2022;
        int dp[N][N];

        int len1 = s1.length(), len2 =s2.length(), last = 0;
        string temp = "";
        
        // Initialization
        for(int i = 0; i< len1; i++) dp[i][0] = 0;
        for(int i = 0; i< len2; i++) dp[0][i] = 0;
        
        // State Transfer
        for(int i = 0;i < len1; i++){
            for(int j = 0; j < len2; j++){
                if(s1[i] == s2[j]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    if (dp[i][j] > last){
                        last = dp[i][j];
                        temp.push_back(s1[i]);
                    }
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        if (dp[len1-1][len2-1] == 0){
            return "-1";
        }
        else{
            return temp;
        }
        
    }
};

int main(){
    string s1 = "abc";
    string s2 = "def";
    Solution S;
    printf("%s",S.LCS(s1, s2).c_str());

    // S.LCS(s1, s2);
    cout << s1 << s2 << endl;
    return 0;
}