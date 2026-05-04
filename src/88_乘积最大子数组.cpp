#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        //以当前结尾的子数组的最大乘积和最小乘积
        int max_res=nums[0];
        int min_res=nums[0];
        //可能会遇到0清空，所以要用res来记录最大值
        int res=nums[0];
        
        for(int i=1;i<n;i++){
            if(nums[i]<0)swap(max_res,min_res);

            max_res = max(nums[i],nums[i]*max_res);
            min_res = min(nums[i],nums[i]*min_res);
            res = max(res,max_res);
        }
        return res;
    }
};