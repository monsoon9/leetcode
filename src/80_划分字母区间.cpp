#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    vector<int> partitionLabels(string s) {
        //遍历第一遍 记录每个字母的终止位置
        int last[26];
        for(int i=0;i<s.length();i++){
            last[s[i]-'a']=i;
        }

        vector<int> res;
        int end=0;
        int start=0;
        for(int i=0;i<s.length();i++){
            end = max(end,last[s[i]-'a']);

            if(end==i){
                res.push_back(end-start+1);
                start=i+1;
            }
        }
        return res;
    }
};