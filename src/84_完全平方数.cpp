#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
//完全背包问题
    int numSquares(int n) {
        vector<int> dp(n+1,n+1);
        dp[0]=0;      

        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                dp[i] = min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};