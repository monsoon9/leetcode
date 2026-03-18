#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>



//方法一 直接重新开一个数组，然后取k余nums.size()的余数 倒序找到起点写入新数组
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> res;
        int start = k%nums.size();
        //从起点到nums的最后一个元素
        for(int i=(nums.size()-start)%nums.size();i<nums.size();i++){
            res.push_back(nums[i]);
        }
        for(int i=0;i<(nums.size()-start)%nums.size();i++){
            res.push_back(nums[i]);
        }
        nums = res;
    }
};
//简化写法
class Solution1 {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);
        for (int i = 0; i < n; ++i) {
            // 计算新位置
            temp[(i + k) % n] = nums[i];
        }
        nums = temp; // 将辅助数组拷贝回原数组
    }
};


//最优解-翻转数组！！！
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        reverse(nums.begin(),nums.end());
        //翻转前k个
        reverse(nums.begin(),nums.begin()+k);
        //翻转k之后的
        reverse(nums.begin()+k,nums.end());
    }
};


