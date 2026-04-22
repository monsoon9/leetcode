#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<algorithm>

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> track;
        int sum=0;
        dfs(candidates,target,res,track,sum,0);
        return res;
    }
    void dfs(vector<int>& candidates,int target,vector<vector<int>>&res,vector<int>&track,int sum,int start){
        if(sum==target){res.push_back(track);return;}
        

        for(int i=start;i<candidates.size();i++){
            if(sum+candidates[i]>target)break;//如果已经超出了target直接回溯
            sum+=candidates[i];
            track.push_back(candidates[i]);
            dfs(candidates,target,res,track,sum,i);
            sum-=candidates[i];
            track.pop_back();
        }
    }
};