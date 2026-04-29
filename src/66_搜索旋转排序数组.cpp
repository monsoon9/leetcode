#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        int mid;

        while(l<=r){
            mid = l+(r-l)/2;
            if(nums[mid]==target)return mid;
            if(nums[l]<=nums[mid]){//左边有序
              if(nums[l]<=target && nums[mid]>=target){//target在左侧区间
                 r = mid-1;
              }else{
                l = mid+1;
              }
        }else{//右侧有序
            if(target>=nums[mid]&&target<=nums[r]){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        }
        return -1;
    }
};