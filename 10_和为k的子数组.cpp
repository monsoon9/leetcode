#include<iostream>
using namespace std;
#include<cstring>
#include<algorithm>
#include<vector>
#include<unordered_map>
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //使用前缀和
        unordered_map<int,int> mp;
        int count=0,pre=0;
        mp[0]=1;//和为0的有0个
        for(int x : nums){
            pre+=x;
            if(mp.count(pre-k)){
                count+=mp[pre-k];
            }
            mp[pre]++;
        }
        return count;
    }
};

// int main(){
//     Solution sol;
//     //测试用例1
//     vector<int> nums1 = {1,1,1};
//     int k1=2;
//     cout<<"test1:"<<(sol.subarraySum(nums1,k1)==2?"passed":"falsed")
//     <<"(Expected 2,Got: "<<sol.subarraySum(nums1,k1)<<")"<<endl;
// }

// int main() {
//     Solution sol;

//     // 测试用例 1
//     vector<int> nums1 = {1, 1, 1};
//     int k1 = 2;
//     cout << "Test Case 1: " << (sol.subarraySum(nums1, k1) == 2 ? "Passed" : "Failed") 
//          << " (Expected 2, Got " << sol.subarraySum(nums1, k1) << ")" << endl;

//     // 测试用例 2
//     vector<int> nums2 = {1, 2, 3};
//     int k2 = 3;
//     cout << "Test Case 2: " << (sol.subarraySum(nums2, k2) == 2 ? "Passed" : "Failed") 
//          << " (Expected 2, Got " << sol.subarraySum(nums2, k2) << ")" << endl;

//     return 0;
// }


#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
class Solution1{
public:
    int subarraySum(vector<int>& nums,int k){
        unordered_map<int,int> mp;
        //初始化
        mp[0]=1;
        //公式：s[i] - s[j-1] = k
        //s[i] - k = s[j-1];说明存在连续子数组和为k
        int count=0,pre=0;
        for(int x:nums){
            pre+=x;
            if(mp.count(pre-k)){
                count+=mp[pre-k];
            }
            mp[pre]++;
        }
        return count;
    }


};


int main(){
    Solution1 sol;
    vector<int> nums1 = {1,1,1};
    int k1=2;
    cout<<"答案在这里哦！！！！！"<<endl;
    cout<<sol.subarraySum(nums1,k1)<<endl;
    return 0;
}