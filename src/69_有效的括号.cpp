#include<iostream>
using namespace std;
#include<stack>

class Solution {
public:
    bool is_match(char a,char b){
        if(a=='('&&b==')')return true;
        else if(a=='['&&b==']')return true;
        else if(a=='{'&&b=='}')return true;
        return false;
    }
    bool isValid(string s) {
        stack<char> st;

        for(auto a:s){
            if(a=='('||a=='['||a=='{'){
                st.push(a);
            }else{
                if(st.empty())return false;
                auto out = st.top();
                st.pop();
                if(is_match(out,a))continue;
                else return false;
            }
        }
        if(st.empty())return true;
        else return false;
    }
};