#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int m=0;
        int n=nums.size();
        //只有一个数据 肯定能到
        if(n==1)return true;
        for(int i=0;i<n;i++){
            m = max(m,nums[i]+i);
            //注意这里m只需要到达n-1即可
            if(m>=(n-1))return true;
            if(i==m && nums[i]==0)return false;
        }
        return false;
    }
};