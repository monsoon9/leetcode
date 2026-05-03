#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int climbStairs(int n) {
        if(n==0)return 0;
        if(n<2)return 1;
        vector<int> memo(n+1);
        memo[0]=0,memo[1]=1,memo[2]=2;
        for(int i=3;i<=n;i++){
            memo[i]=(memo[i-1]+memo[i-2]);
        }
        return memo[n];
    }
};


class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)return n;
        int current=0;
        int pre1=1,pre2=2;
        for(int i=3;i<=n;i++){
            current=pre1+pre2;
            pre1=pre2;
            pre2=current;
        }
        return current;
    }
};