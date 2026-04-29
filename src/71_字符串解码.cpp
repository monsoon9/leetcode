#include<iostream>
using namespace std;
#include<stack>
#include<string>
class Solution {
public:
    string decodeString(string s) {
        stack<int> dataStack;
        stack<string> stringStack;
        string curString="";
        int k=0;


        for(auto cur:s){
            if(isdigit(cur)){
                k = k*10+(cur-'0');
            }else if(cur=='['){
                dataStack.push(k);
                stringStack.push(curString);
                k=0;
                curString="";
            }else if(cur==']'){
                string tmp = curString;
                curString = stringStack.top();
                stringStack.pop();
                int times = dataStack.top();
                dataStack.pop();
                while(times>0){
                    curString+=tmp;
                    times--;
                }
            }else curString+=cur;
        }
        return curString;
    }
};