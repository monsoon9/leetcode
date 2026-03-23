#include<iostream>
using namespace std;
#include<vector>

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //使用哑结点
        ListNode* dummy = new ListNode(0,head);
        ListNode* prev = dummy;

        //当后面至少有两个结点的时候才进行交换
        while(prev->next!=nullptr && prev->next->next!=nullptr){
            ListNode* node1 = prev->next;
            ListNode* node2 = prev->next->next;
            prev->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            prev = node1;
        }

        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};