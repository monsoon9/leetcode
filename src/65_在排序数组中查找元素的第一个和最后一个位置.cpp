#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = search_bound(nums,target,true);
        if(left==-1)return {-1,-1};
        int right = search_bound(nums,target,false);
        return {left,right};
    }

    int search_bound(vector<int>& nums,int target,bool isFirst){
        int l=0,r=nums.size()-1,mid,ans=-1;
        while(l<=r){
            mid = l + (r-l)/2;
            if(nums[mid]>target){
                r = mid-1;
            }
            else if(nums[mid]<target){
                l = mid+1;
            }else{
                if(isFirst){
                    ans=mid;
                    r=mid-1;
                }else{
                    ans=mid;
                    l=mid+1;
                }
            }
        }
        return ans;
    }
};