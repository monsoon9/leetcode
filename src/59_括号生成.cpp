#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string track = "";
        vector<string> res;
        dfs(n,0,0,res,track);
        return res;
    }
    void dfs(int n,int left,int right,vector<string>&res,string&track){
        if(left==right&&left==n){
            res.push_back(track);
            return;
        }

        //放左括号
        if(left<n){
            track.push_back('(');
            dfs(n,left+1,right,res,track);
            track.pop_back();
        }

        //放右括号
        if(right<left){
            track.push_back(')');
            dfs(n,left,right+1,res,track);
            track.pop_back();
        }
    }
};