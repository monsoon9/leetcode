#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<queue>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        //统计频率
        for(auto num:nums){
            freq[num]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;

        for(auto& [num,count]:freq){
            minHeap.push({count,num});
            if(minHeap.size()>k)minHeap.pop();
        }

        //输出结果
        vector<int> res;
        while(!minHeap.empty()){
            auto [count,num] = minHeap.top();
            minHeap.pop();
            res.push_back(num);
        }

        return res;
        
    }
};