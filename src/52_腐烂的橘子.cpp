#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        if(rows==0)return 0;
        int cols = grid[0].size();

        queue<pair<int,int>> q;

        int fresh = 0;
        int broken = 0;
        //记录fresh的数量和broken的位置
        for(int i =0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2)q.push({i,j});
                else if(grid[i][j]==1)fresh++;
            }
        }

        if(fresh==0)return 0;

        int minutes = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        //开始bfs扩散
        while(!q.empty()&&fresh>0){
            int size = q.size();
            minutes++;

            //遍历这一层腐烂的橘子
            for(int i =0;i<size;i++){
                auto [r,c] = q.front();
                q.pop();

                //将四个方向的新鲜橘子都变成腐烂的
                for(auto& d : dirs){
                    int nr = r+d[0];
                    int nc = c+d[1];
                    //如果坐标合法且为新鲜橘子就让它腐烂
                    if(nr>=0 && nc>=0 && nr<rows && nc<cols && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        fresh--;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return fresh==0 ? minutes : -1;
    }
};