#include<iostream>
using namespace std;
#include<vector>
#include<queue>

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // string track;
        int index = 0;
        char first = word[0];
        int n = board.size();
        int m = board[0].size();
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==first){
                    if(dfs(board,word,index,i,j))return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word,int index,int n,int m){
        if(index==word.length())return true;
        if(n<0||n>=board.size()||m<0||m>=board[0].size()||board[n][m]!=word[index]){
            return false;
        }

        //技巧为了避免重复使用，使用/0来标记
        char temp = board[n][m];
        board[n][m] = '1';

        bool found = dfs(board,word,index+1,n+1,m)||dfs(board,word,index+1,n-1,m)||
        dfs(board,word,index+1,n,m+1)||dfs(board,word,index+1,n,m-1);

        //回溯
        board[n][m] = temp;
        return found;
    }
};