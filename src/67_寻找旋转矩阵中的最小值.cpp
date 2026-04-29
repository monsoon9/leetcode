#include<iostream>
using namespace std;
#include<vector>


//找最小值 必须使用l<r;r=mid;因为这样跳出循环l=r
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0,r=nums.size()-1;
        int mid;
        while(l<r){
            mid = l+(r-l)/2;
            if(nums[mid]>nums[r]){//说明最小值在右侧
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return nums[l];
    }
};