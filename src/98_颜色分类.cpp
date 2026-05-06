#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//三指针法
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int p1=0,cur=0,p2=n-1;
        while(cur<=p2){
            if(nums[cur]==0){
                swap(nums[cur],nums[p1]);
                p1++;
                cur++;
            }else if(nums[cur]==1){
                cur++;
            }else if(nums[cur]==2){
                swap(nums[cur],nums[p2]);
                p2--;
            }
        }
    }
};