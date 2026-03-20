#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_map<int,int> hash;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                hash[matrix[i][j]]++;
            }
        }

        if(hash.count(target))return true;
        else return false;
    }
};


//Z字查找 从右上角开始查找
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row=0,col=m-1;//从右上角开始查找
        while(row<n&&col>=0){
            if(matrix[row][col]==target)return true;
            else if(matrix[row][col]>target)col--;//此时右下角的所有数都大于target
            else row++;
        }
        return false;
    }
};