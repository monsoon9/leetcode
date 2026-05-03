#include<iostream>
using namespace std;
#include<vector>


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for(int i=0;i<numRows;i++){
            //每一行有i+1个元素，默认初始化为1
            vector<int> row(i+1,1);

            //从第三行开始
            for(int j=1;j<i;j++){
                row[j]=res[i-1][j-1]+res[i-1][j];
            }
            res.push_back(row);
        }
        return res;
    }
};