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
    ListNode* reverseList(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur!=nullptr){
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        //写一个哑结点
        ListNode* dummy = new ListNode(0,head);
        ListNode* pre = dummy;
        ListNode* end = dummy;

        while(end->next!=nullptr){
            //找到当前组的末尾 end是要翻转部分的最后一个元素
            for(int i=0;i<k&&end!=nullptr;i++)end = end->next;
            if(end==nullptr)break;

            //记录关键位置 pre是要翻转部分的前一个元素
            ListNode* start = pre->next;
            ListNode* nextGroup = end->next;

            //断开 然后翻转
            end->next = nullptr;
            pre->next = reverseList(start);

            //连接回来
            start->next = nextGroup;

            //移动指针 准备下一组
            pre = start;
            end = pre;
        }
        return dummy->next;
    }
};