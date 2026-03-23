#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0),next(nullptr) {}
    ListNode(int x) : val(x),next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x),next(next) {} 
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //让两个链表都走完a和b的路程 一定可以同时到达交点 或者同时到达nullptr
        ListNode* pa=headA;
        ListNode* pb = headB;

        while(pa!=pb){
            pa==nullptr ? pa=headB : pa = pa->next;
            pb==nullptr ? pb=headA : pb = pb->next;
        }
        return pa;
    }
};