#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0,candidate=0;
        for(int num:nums){
            if(count==0)
            {candidate=num;count++;}
            else{
                if(num==candidate)count++;
                else count--;
            }
        }
        return candidate;
    }
};