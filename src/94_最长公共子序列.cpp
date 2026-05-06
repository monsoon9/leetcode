#include<iostream>
using namespace std;
#include<vector>
#include<string>


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        //dp[i][j]:表示text1的前i个；text2前j个 最大公共子序列长度
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //这里注意 当匹配的时候是dp[i][j]=dp[i-1][j-1]+1
                if(text1[i-1]==text2[j-1])dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};