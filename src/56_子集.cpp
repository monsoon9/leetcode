#include<iostream>
using namespace std;
#include<vector>


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;
        dfs(nums,0,res,track);//这里的0表示从哪里开始，避免重复
        return res;
    }

    void dfs(vector<int>&nums,int start,vector<vector<int>>&res,vector<int>&track){
        res.push_back(track);

        for(int i=start;i<nums.size();i++){
            track.push_back(nums[i]);
            dfs(nums,i+1,res,track);

            track.pop_back();
        }
    }
};