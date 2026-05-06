#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,0));
        //dp[i][j]表示到目前位置的路径数量
        //第一排和第一列初始化为1
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }
        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};




//简化
#include <vector>
#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        // 创建一个大小为 n 的数组，初始化为 1
        // 因为第一行每个点只有 1 种路径
        std::vector<int> dp(n, 1);
        
        // 从第二行开始遍历
        for (int i = 1; i < m; ++i) {
            // 从第二列开始更新
            for (int j = 1; j < n; ++j) {
                // 当前格子的路径数 = 上方的路径数(dp[j]) + 左侧的路径数(dp[j-1])
                dp[j] += dp[j - 1];
            }
        }
        
        return dp[n - 1];
    }
};