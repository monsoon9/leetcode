#include<iostream>
using namespace std;
#include<queue>
#include<vector>


//使用两个堆
class MedianFinder {
    private:
        priority_queue<int,vector<int>,greater<int>>minHeap;
        priority_queue<int>maxHeap;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //先把所有元素放到大顶堆中，然后再把大顶堆的top移动到小顶堆中
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if(minHeap.size()>maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(minHeap.size()==maxHeap.size()){
            return (minHeap.top()+maxHeap.top())/2.0;
        }else return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */