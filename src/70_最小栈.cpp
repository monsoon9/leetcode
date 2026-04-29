#include<iostream>
using namespace std;
#include<stack>

class MinStack {
    private:
    stack<int> dataStack;//存储数据
    stack<int> minStack;//存储最小值

public:
    MinStack() {
        
    }
    
    void push(int val) {
        dataStack.push(val);

        if(minStack.empty()){
            minStack.push(val);
        }else{
            minStack.push(min(val,minStack.top()));
        }
    }
    
    void pop() {
        if(!dataStack.empty()){
            dataStack.pop();
            minStack.pop();
        }
    }
    
    int top() {
        return dataStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


 class MinStack {
private:
    stack<pair<int,int>> s;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()) s.push(make_pair(val,val));
        else s.push(make_pair(val,min(val,s.top().second)));
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */