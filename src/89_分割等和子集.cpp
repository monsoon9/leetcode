#include<iostream>
using namespace std;
#include<vector>
#include<iostream>

// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int s;
//         for(int num:nums){
//             s+=num;
//         }
//         if(s%2==1)return false;
//         int half=s/2;
//         //找一半的值能不能加出来，退化为01背包问题
//         vector<int> dp(half);
//         for(int i=0;i<nums.size();i++){

//         }


//     }
// };



class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) sum += n;
        if (sum % 2 != 0) return false; // 奇数直接排除

        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true; // 基础：和为0总是可达的（什么都不选）

        for (int num : nums) {
            for (int j = target; j >= num; j--) {
                if (dp[j - num]) {
                    dp[j] = true;
                }
            }
        }
        return dp[target];
    }
};