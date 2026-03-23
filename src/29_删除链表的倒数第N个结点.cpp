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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //创建哑结点
        ListNode* dummy = new ListNode(0,head);
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = dummy;
        
        //先让fast走n步
        for(int i=0;i<n;i++){
            fast = fast->next;
        }

        //fast和slow一起移动
        while(fast!=nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }

        //删除节点
        prev->next = slow->next;

        //保存头节点
        ListNode* res = dummy->next;

        //释放内存
        delete slow;
        delete dummy;

        return res;
    }
};