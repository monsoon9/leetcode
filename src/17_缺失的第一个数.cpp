#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ans=-1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            //为负数直接pass
            if(nums[i]<=0)continue;
            //当出现第一个整数且不为1，且前一个数是负数，则答案就是该数1
            else if(i>=1 && nums[i]>1 && nums[i-1]<=0){ans = 1;break;}
            //第一个数就不是负数且不为1的时候
            else if(i==0 && nums[i]>1){ans=1;break;}
            //当出现连续整数的时候
            else if(i>=1 && nums[i-1]>0 && nums[i-1]!=nums[i]-1 && nums[i]!=nums[i-1]){ans = nums[i-1]+1;break;}
        }
        //遍历完循环都没有赋值ans 说明该数组一直连续 或者 所有都为负数
        if(nums[nums.size()-1]<=0)return 1;
        return ans==-1? nums[nums.size()-1]+1 : ans;
    }
};



//上述方法过于繁琐，判断情况如果不到位就ac不了
//我们可以采用数组下标原地哈希
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        //将所有元素放到其值-1的下标处
        for(int i=0;i<n;i++){
            //使用while 因为交换回来的数可能也得继续交换
            //如果一个数出现两次就跳不出while 所以写上nums[nums[i]-1]!=nums[i]
            while(nums[i]>0 && nums[i]<n && nums[nums[i]-1]!=nums[i]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }


        //遍历数组 找到第一个鸠占鹊巢的数
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1)return i+1;
        }

        //若所有的数都在自己位置上 则说明数组连续
        return n+1;
    }
};