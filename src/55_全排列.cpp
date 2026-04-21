#include<iostream>
#include<vector>
using namespace std;
#include<queue>

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;//记录路径
        vector<bool> visited(nums.size(),false);
        dfs(nums,track,visited,res);
        return res;
    }

    void dfs(vector<int>& nums,vector<int>& track,vector<bool>& visited,vector<vector<int>>& res){
        if(track.size()==nums.size()){
            res.push_back(track);
            return;
        }
        for(int i=0;i<nums.size();i++){
            //遍历每个元素作为表头
            if(visited[i])continue;

            track.push_back(nums[i]);
            visited[i]=true;

            dfs(nums,track,visited,res);

            //回溯
            track.pop_back();
            visited[i]=false;
        }
    }
};