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
    bool hasCycle(ListNode *head) {
        // 特判：如果链表为空或只有一个节点且无环，直接返回 false
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        //1-2步长的两个指针，如果相遇就是有环 没相遇到nullptr就是无环
        ListNode* pa = head;
        ListNode* pb = head;
        while(pa!=nullptr && pa->next!=nullptr){
            pa=pa->next->next;
            
            pb = pb->next;

            if(pa==pb)return true;
        }
        return false;
    }
};