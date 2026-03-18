// #include<iostream>
// using namespace std;
// #include<vector>
// #include<queue>
// #include<deque>

// //使用优先队列
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         deque<int> q;//这里存储的是下标
//         vector<int> res;
//         for(int i=0;i<nums.size();i++){
//             while(!q.empty() && nums[i]>=nums[q.back()]){
//                 q.pop_back();
//             }
//             q.push_back(i);

//             if(i-k==q.front()){
//                 q.pop_front();
//             }

//             //窗口形成
//             if(i>=k-1){
//                 res.push_back(nums[q.front()]);
//             }
//         }

//         return res;
//     }
// };


// int main(){
//     vector<int> nums1 = {1,3,-1,-3,5,3,6,7};
//     int k1 = 3;

//     Solution sol;
//     vector<int> ans = sol.maxSlidingWindow(nums1,k1);
//     for(int x:ans){
//         cout<<x<<" ";
//     }cout<<endl;
//     return 0;
// }



// //使用大顶堆
// class Solution1 {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         priority_queue<pair<int,int>> pq;
//         //将第一个窗口数据先存储到大顶堆中
//         for(int i=0;i<k;i++) pq.push({nums[i],i});

//         //遍历整个数组，当第一个元素超出窗口就pop
//         vector<int> res = {pq.top().first};
//         for(int i=k;i<nums.size();i++){
//             pq.push({nums[i],i});
//             while(pq.top().second<=i-k){//弹出不在窗口中的数据
//                 pq.pop();
//             }
//             res.push_back(pq.top().first);
//         }
//         return res;

//     }
// };























#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include<queue>



// //单调队列
// class Solution1{
//     public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         deque<int> dq;//存下标
//         vector<int>res;

//         //从头开始遍历
//         for(int i=0;i<nums.size();i++){
//             //队列不为空的时候，判断队列中的最小值(back)和目前进来的值的大小
//             while(!dq.empty() && nums[i]>=nums[dq.back()]){
//                 dq.pop_back();
//             }
//             dq.push_back(i);

//             //当目前最大值不在窗口范围内时pop front
//             if(dq.front()<=i-k){
//                 dq.pop_front();
//             }

//             //窗口形成之后开始记录最大值
//             if(i>=k-1){
//                 res.push_back(nums[dq.front()]);
//             }
//         }
//         return res;
//     }
// };

//大顶推
class Solution{
    public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        //先建立窗口
        for(int i=0;i<k;i++)pq.push({nums[i],i});
        //记录数组
        vector<int> res;
        res.push_back(pq.top().first);

        //遍历
        for(int i=k;i<nums.size();i++){
            //加入新元素
            pq.push({nums[i],i});
            
            //当最大元素超出窗口就踢出
            while(pq.top().second <= i-k)pq.pop();

            //记录最大值
            res.push_back(pq.top().first);
        }
        return res;
    }
};



int main(){
    vector<int> nums = {9,10,9,-7,-4,-8,2,-6};
    int k = 5;
    Solution sol;
    vector<int> ans = sol.maxSlidingWindow(nums,k);

    for(int x:ans){
        cout<<x<<" ";
    }cout<<endl;

    return 0;
}