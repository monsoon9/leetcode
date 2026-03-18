#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//前缀积和后缀积
//ans[i] = 前缀积*后缀积
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n);
        ans[0]=1;

        //先计算前缀积
        for(int i=1;i<n;i++){
            ans[i] = ans[i-1]*nums[i-1];
        }

        //计算后缀积，从后往前之间计算出答案
        int pre = 1;
        for(int i=n-1;i>=0;i--){
            ans[i] = ans[i] * pre;
            pre *= nums[i];
        }
        return ans;
    }
};