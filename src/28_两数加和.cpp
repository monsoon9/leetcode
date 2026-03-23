#include<bits/stdc++.h>
using namespace std;
#include<iostream>
#include<cstring>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       
        int a = 0;
        ListNode* head = l1;
        ListNode* prev = nullptr;

        //当l1结束 l2结束 进位a结束的时候 所有的加法才结束
        while(l1!=nullptr || l2!=nullptr || a!=0){
            //当l1空了 l2还没空
            if(l1==nullptr){
                l1 = new ListNode(0);
                prev->next = l1;
            }
            int val1 = l1->val;
            int val2 = l2==nullptr ? 0 : l2->val;
            int add1 = val1+val2 + a;

            l1->val = add1%10;
            a = add1/10;

            if(l2!=nullptr)l2 = l2->next;
            prev = l1;
            l1 = l1->next;
        }
        return head;
    }
};