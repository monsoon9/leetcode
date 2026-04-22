#include<iostream>
using namespace std;
#include<vector>
#include<queue>

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> track;
        dfs(res,track,0,s);
        return res;
    }

    void dfs(vector<vector<string>> &res,vector<string>&track,int start,string &s){
        if(start==s.length()){   
            res.push_back(track);
            return;
        }

        for(int i=start;i<s.length();i++){
            if(judge(s.substr(start,i-start+1))){
                track.push_back(s.substr(start,i-start+1));
                dfs(res,track,i+1,s);
                track.pop_back();
            }
        }
    }

    bool judge(string a){
        int l=0,r=a.length()-1;
        while(l<r){
            if(a[l]!=a[r])return false;
            l++;
            r--;
        }
        return true;
    }
};