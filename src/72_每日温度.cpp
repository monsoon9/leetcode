#include<iostream>
using namespace std;
#include<vector>
#include<stack>



class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n,0);
        stack<int> index;
        

        for(int i=0;i<n;i++){
            
            while(!index.empty()&&temperatures[i]>temperatures[index.top()]){
                res[index.top()]=i-index.top();
                index.pop();
            }
            index.push(i);
        }
        return res;
    }
};