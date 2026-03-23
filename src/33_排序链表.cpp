#include<iostream>
using namespace std;
#include<algorithm>

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include<vector>
class Solution {
public:
    ListNode* sortList(ListNode* head) {
       vector<int> res;
       ListNode* curr = head;
       while(curr!=nullptr){res.push_back(curr->val);curr = curr->next;}
       sort(res.begin(),res.end());
       //直接覆盖原链表
       curr = head;
       int count = 0;
       for(int x:res){
        curr->val = x;
        curr = curr->next;
       }
       return head;
    }
};


//归并排序 好好看一下
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // 1. 递归终止条件
        if (head == nullptr || head->next == nullptr) return head;

        // 2. 找到链表中点并断开
        ListNode* mid = getMid(head);
        ListNode* leftHead = head;
        ListNode* rightHead = mid->next;
        mid->next = nullptr; // 切断链表

        // 3. 递归排序左右两部分
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        // 4. 合并两个有序链表
        return merge(leftHead, rightHead);
    }

private:
    // 快慢指针寻找中点
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next; // 保证偶数长度时返回前半段末尾
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // 合并两个有序链表 (之前我们写过类似的逻辑)
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = (l1 != nullptr) ? l1 : l2;
        return dummy.next;
    }
};