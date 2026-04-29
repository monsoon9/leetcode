#include<iostream>
using namespace std;
#include<vector>
#include<stack>


//单调栈
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);
        int n = heights.size();
        int res=0;

        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[i]<heights[st.top()]){
                //以st.top作为高的矩阵的面积
                int height = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : i-st.top()-1;
                res = max(res,width*height);
            }
            st.push(i);
        }
        return res;
    }
};