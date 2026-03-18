// #include<iostream>
// using namespace std;
// #include<vector>
// #include<unordered_map>
// #include<climits>

// class Solution {
// public:
//     string minWindow(string s, string t) {
//         if(t.size()>s.size())return "";
//         if(t==s)return t;
//         unordered_map<char,int> need,window;
//         for(char c:t)need[c]++;
        
//         int left=0,right=0;
//         int start=0,len=INT_MAX;
//         int valid = 0;//记录种类
//         while(right<s.length()){
//             char c = s[right];
//             right++;

//             if(need.count(c)){
//                 window[c]++;
//                 if(window[c]==need[c])valid++;//如果window中的该字母达到了need中的要求valid+1
//             }

//             //判断左窗口是否需要收缩
//             //此处need是哈希表size相当于种类数量
//             while(valid==need.size()){
//                 //更新子串
//                 if(right-left<len){
//                     len=right-left;
//                     start = left;
//                 }
//                 char d = s[left];
//                 left++;

//                 if(need.count(d)){
//                     if(window[d]==need[d])valid--;
//                     window[d]--;
//                 }
//             }
//         }
//         return len==INT_MAX ? "" : s.substr(start,len);
//     }
// };


// int main(){
//     string s = "ADOBECODEBANC";
//     string t = "ABC";
//     Solution sol;
//     cout<<"答案在这："<<endl;
//     cout<<sol.minWindow(s,t)<<endl;
//     return 0;
// }


#include<iostream>
using namespace std;
#include<cstring>
#include<vector>
#include<unordered_map>
#include<climits>
class Solution{
    public:
    string minWindow(string s,string t){
        unordered_map<char,int> need,window;
        //先把need给存好
        for(char c:t)need[c]++;
        int left=0,right=0;
        int start=0,len=INT_MAX;
        int valid = 0;//记录凑够了多少种类
        //开始遍历
        while(right<s.length()){
            //取出字符，然后右移right
            char c = s[right];
            right++;

            //当在need中进行判断
            if(need.count(c)){
                window[c]++;
                //当window中的数量与need相等则说明凑够了一个字母种类的数量
                if(need[c]==window[c])valid++;
            }

            //当valid==need.size的时候说明字串符合need，但是不是最短的要右移动left寻找最短的len
            while(valid==need.size()){
                //更新字串
                if(right-left<len){
                    start=left;
                    len = right-left;
                }
                char d = s[left];
                left++;
                //如果d在need中则减少数量
                if(need.count(d)){
                    //当window中的字母数量少于need的时候种类少一个valid-1
                    if(need[d]==window[d])valid--;
                    window[d]--;
                }
            }
        }
        return len==INT_MAX ? "" : s.substr(start,len);
    }
};