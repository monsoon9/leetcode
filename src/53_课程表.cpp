#include<iostream>
using namespace std;
#include<vector>
#include<queue>

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);//计算入度
        vector<vector<int>> adj(numCourses);//邻接表

        for(auto& edge : prerequisites){
            int course = edge[0];
            int pre = edge[1];
            adj[pre].push_back(course);
            indegree[course]++;
        }

        //将所有零入度的放入队列
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }

        int count = 0;
        //开始bfs
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            count++;
            for(int nextCourse : adj[cur]){
                indegree[nextCourse]--;
                if(indegree[nextCourse]==0)q.push(nextCourse);
            }
        }
        return count==numCourses;
    }
};