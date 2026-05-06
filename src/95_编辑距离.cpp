#include<iostream>
using namespace std;
#include<vector>
#include<string>


class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();

        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        // 2. 关键：初始化边界条件
        for (int i = 0; i <= n; i++) dp[i][0] = i; // 删除操作
        for (int j = 0; j <= m; j++) dp[0][j] = j; // 插入操作
        //dp[i][j]:word1的前i个变成word2的前j个 需要最少步数
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1])dp[i][j]=dp[i-1][j-1];//如果二者匹配
                //若不匹配,则在三种操作中取最小值+1
                //插入：dp[i][j-1] + 1
                // 删除：dp[i-1][j] + 1
                // 替换：dp[i-1][j-1] + 1
                else{
                    dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                }

            }
        }
        return dp[n][m];
    }
};