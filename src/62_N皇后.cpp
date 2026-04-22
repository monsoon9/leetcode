#include<iostream>
using namespace std;
#include<vector>
#include<queue>

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> track(n,string(n,'.'));
        dfs(n,res,track,0);
        return res;
    }

    void dfs(int n,vector<vector<string>>& res,vector<string>& track,int row){
        if(row==n){
            res.push_back(track);
            return;
        }

        for(int col=0;col<n;col++){
            if(!isvalid(track,row,col))continue;
            track[row][col]='Q';
            dfs(n,res,track,row+1);
            track[row][col]='.';
        }
    }

    bool isvalid(vector<string>& track,int row,int col){
        //判断列是否冲突
        for(int i=0;i<row;i++){
            if(track[i][col]=='Q')return false;
        }
        
        //判断左上角是否冲突
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(track[i][j]=='Q')return false;
        }

        //判断右上角是否冲突
        for(int i=row-1,j=col+1;i>=0&&j<track.size();i--,j++){
            if(track[i][j]=='Q')return false;
        }
        return true;
    }
};