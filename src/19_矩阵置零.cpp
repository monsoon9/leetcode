#include<iostream>
using namespace std;
#include<vector>


//记录所有的0 然后再将数组中0的行和列置零
class Solution {

public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();//行
        int m = matrix[0].size();//列
        vector<pair<int,int>> zero;
        //存储0的坐标
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0)zero.push_back({i,j});
            }
        }

        //开始置零
        for(auto a : zero){
            int row = a.first;
            setzero_row(matrix,row);
            int col = a.second;
            setzero_col(matrix,col);
        }

    }

    //行置零
    void setzero_row(vector<vector<int>>& matrix,int row){
        int m = matrix[0].size();
        for(int i=0;i<m;i++){
            matrix[row][i]=0;
        }
    }

    //列置零
    void setzero_col(vector<vector<int>>& matrix,int col){
        int n = matrix.size();
        for(int i=0;i<n;i++){
            matrix[i][col]=0;
        }
    }
};



//使用第一行和第一列来存储zero，优化为o(1)
class Solution {

public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();//行
        int m = matrix[0].size();//列
        //得单独处理一下(0,0)为零的情况
        int row_flag=-1,col_flag=-1;//(0,0)为零行和列的标记
        //存储0的坐标
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    if(i==0)row_flag=1;
                    if(j==0)col_flag=1;
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                };
            }
        }

        //开始置零
        //置零行
        for(int i=1;i<n;i++){
            if(matrix[i][0]==0)setzero_row(matrix,i);
        }
        //置零列
        for(int i=1;i<m;i++){
            if(matrix[0][i]==0)setzero_col(matrix,i);
        }

        //开始处理(0,0)是否为0
        if(col_flag==1)setzero_col(matrix,0);
        if(row_flag==1)setzero_row(matrix,0);

    }

    //行置零
    void setzero_row(vector<vector<int>>& matrix,int row){
        int m = matrix[0].size();
        for(int i=0;i<m;i++){
            matrix[row][i]=0;
        }
    }

    //列置零
    void setzero_col(vector<vector<int>>& matrix,int col){
        int n = matrix.size();
        for(int i=0;i<n;i++){
            matrix[i][col]=0;
        }
    }
};