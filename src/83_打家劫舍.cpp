#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        vector<int> memo(n);
        memo[0]=nums[0];
        memo[1]=max(nums[0],nums[1]);

        for(int i=2;i<n;i++){
            memo[i]=max(memo[i-1],memo[i-2]+nums[i]);
        }
        return memo[n-1];
    }
};



#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int prev2 = 0;        // dp[i-2]
        int prev1 = nums[0];  // dp[i-1]
        
        for (int i = 1; i < n; ++i) {
            int current = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
};