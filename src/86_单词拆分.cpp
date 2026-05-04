#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<unordered_set>

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set(wordDict.begin(),wordDict.end());
        int n=s.length();
        vector<bool> dp(n+1,false);
        dp[0]=true;
        
        //遍历每个字符，确定直到现在这个char 能不能组成
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j] && word_set.find(s.substr(j,i-j))!=word_set.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};