#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

class Solution {
    private:
    unordered_map<char,string> phoneMap ={
        {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
        {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxzy"}
    };

    void dfs(string &digits,string&track,int index,vector<string>&res){
        if(index==digits.length()){
            res.push_back(track);
            return;
        }

        //获取当前的字母
        char digit = digits[index];
        string letters = phoneMap[digit]; 

        for(auto letter:letters){
            track.push_back(letter);
            dfs(digits,track,index+1,res);
            track.pop_back();//回溯
        }
    }




public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string track;
        dfs(digits,track,0,res);
        return res;
    }
};