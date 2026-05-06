#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //位运算，异或
        int res=nums[0];
        for(int i=1;i<nums.size();i++){
            res^=nums[i];
        }
        return res;
    }
};