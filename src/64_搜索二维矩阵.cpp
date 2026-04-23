#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = search_row(matrix,target);
        if (row == -1) return false; // target 比矩阵最小值还小
        if(matrix[row][0]==target)return true;
        int l = 0,r=matrix[0].size()-1;
        int mid;
        while(l<=r){
            mid = l+(r-l)/2;
            if(matrix[row][mid]==target)return true;
            if(matrix[row][mid]<target)l=mid+1;
            else r=mid-1;
        }
        return false;
    }

    int search_row(vector<vector<int>>& matrix,int target){
        int l=0,r=matrix.size()-1;
        int mid;
        while(l<=r){
            mid = l+(r-l)/2;
            if(matrix[mid][0]==target)return mid;
            if(matrix[mid][0]<target){
                l=mid+1;
            }else{
                r = mid-1;
            }
        }
        return r;
    }
};