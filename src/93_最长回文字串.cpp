#include<iostream>
using namespace std;
#include<vector>



//中心拓展法
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()==0)return "";
        //中心分为奇数和偶数
        int len=0;
        int start=0,end=0;
        for(int i=0;i<s.length();i++){
            int len1=e(s,i,i);
            int len2=e(s,i,i+1);
            len = max(len1,len2);

            if(len>end-start+1){
                start = i-(len-1)/2;
                end = i+len/2;
            }
        }

        return s.substr(start,end-start+1);
    }

    int e(string& s,int left,int right){
        while(left>=0 && right<s.length() && s[left]==s[right]){
            left--;
            right++;
        }
        //这里的right和left是不匹配的时候的；不是回文串的左右边界
        return right-left-1;
    }
};