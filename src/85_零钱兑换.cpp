#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //若当前dp中的数为amount+1则表示不可达
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;

        //遍历每个数
        for(int i=0;i<=amount;i++){
            //遍历每个硬币
            for(int coin : coins){
                if(coin<=i){
                    dp[i] = min(dp[i],dp[i-coin]+1);
                }
            }
        }
        return dp[amount]>amount ? -1 : dp[amount];
    }
};