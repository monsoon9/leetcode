#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //根据起点排序
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        // int left,right;
        vector<vector<int>> res;
        //记录第一个区间
        vector<int> tmp = {intervals[0][0],intervals[0][1]};

        for(int i=1;i<n;i++){
            int l = intervals[i][0],r = intervals[i][1];
            //如果此时的l大于之前的right 则是一个新的区间
            if(l>tmp[1]){
                //存入tmp，更新tmp，更新left和right
                res.push_back(tmp);
                tmp = intervals[i];
            }
            else{
                tmp[1] = max(tmp[1],r);
            }
        }
        res.push_back(tmp);
        return res;
    }
};




//测试一下sort
