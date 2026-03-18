#include<iostream>
using namespace std;
#include<vector>
#include<climits>


//暴力 超时
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int m=0;
        //以每个点为起点计算每个起点的最大子数组值
        for(int i=0;i<n;i++){
            int m_i=INT_MIN;
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                m_i = max(m_i,sum);
            }
            m = max(m_i,m);
        }
        return m;
    }
};

//可以比较当前累加值和目前这个值的大小 如果目前值大小>累加值 就更换起点
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int m=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            //目前值>=之前的和 更换起点
            if(sum<=nums[i]){
                sum = nums[i];
            }
            m = max(m,sum);
        }
        return m;
    }
};
