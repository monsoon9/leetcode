#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1)return 0;
        int n=nums.size()-1;
        int m=0;
        int pre=0;
        int count=0;
        for(int i=0;i<=n;i++){
            m = max(m,i+nums[i]);
            if(i==pre){
                count++;
                pre=m;
                //判断是否跳出必须写在i==pre里面
                if(m>=n)break;
            }
        }
        return count;
    }
};