#include<iostream>
using namespace std;
#include<vector>


//直接寻找坐标之间的关系，n/2次循环 层遍历
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int t = n/2;
        for(int i=0;i<t;i++){
            for(int j = i;j<n-i-1;j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];//左到上
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];//下到左
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];//右到下
                matrix[j][n-1-i] = tmp;
            }
        }
    }
};


//进阶解法 
//顺时针90:上下翻转 + 主对角线翻转
//逆时针90:左右翻转 + 主对角线翻转
void rotateCounterClockwise(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // 1. 左右翻转 (Left-Right Flip)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            swap(matrix[i][j], matrix[i][n - 1 - j]);
        }
    }
    
    // 2. 主对角线翻转 (Transpose)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}