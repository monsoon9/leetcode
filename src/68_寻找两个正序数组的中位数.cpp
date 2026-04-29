#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())return findMedianSortedArrays(nums2,nums1);

        int m=nums1.size(),n=nums2.size();
        int leftTotal = (nums1.size()+nums2.size()+1)/2;
        int l = 0,r = m;

        while(l<=r){
            int mid = l+(r-l)/2;
            int mid2 = leftTotal-mid;
            
            int L1 = (mid==0) ? INT_MIN : nums1[mid-1];
            int R1 = (mid==m) ? INT_MAX : nums1[mid];
            int L2 = (mid2==0) ? INT_MIN : nums2[mid2-1];
            int R2 = (mid2==n) ? INT_MAX : nums2[mid2];

            if(L1<=R2 && L2<=R1){//完美符合左边都小于右边
                if((m+n)%2==0){//如果是偶数
                    return ((max(L1,L2)+min(R1,R2))/2.0);
                }else{//奇数
                    return max(L1,L2);
                }
            }else if(L1>R2){//让切分点左移
                r = mid-1;
            }else{//让切分点右移
                l = mid+1;
            }
        }
        return 0.0;
    }
};