#include<iostream>
using namespace std;
#include<vector>



class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int res=1;//记录最大值
        //默认每个数字的最小长度都是1
        vector<int> dp(n+1,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                dp[i]=max(dp[i],dp[j]+1);
                res=max(res,dp[i]);
                }      
            }
        }
        return res;
    }
};