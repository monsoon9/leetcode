#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX));
        //dp[i][j]:就是到达该点的最小距离
        dp[1][1]=grid[0][0];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //一定要把起点跳过了
                if(i==1&&j==1)continue;
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i-1][j-1];
            }
        }
        return dp[n][m];
    }
};