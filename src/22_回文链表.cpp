#include <bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


 //链表转数组
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> res;
        ListNode* a = head;
        while(a!=nullptr){
            res.push_back(a->val);
            a = a->next;
        }
        vector<int> b = res;
        reverse(res.begin(),res.end());
        if(res == b)return true;
        return false;
    }
};


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // 1. 找到中点 (快慢指针)
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. 反转后半部分链表 (slow->next 开始的部分)
        ListNode* secondHalf = reverseList(slow->next);

        // 3. 比较前半部分和反转后的后半部分
        ListNode* p1 = head;
        ListNode* p2 = secondHalf;
        bool result = true;
        while (p2 != nullptr) {
            if (p1->val != p2->val) {
                result = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        // (可选) 恢复链表结构：再次反转 secondHalf 接回 slow->next
        return result;
    }

private:
    // 辅助函数：原地反转链表
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};



//栈
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode* curr = head;
        while (curr) {
            s.push(curr->val);
            curr = curr->next;
        }
        curr = head;
        while (curr) {
            if (curr->val != s.top()) return false;
            s.pop();
            curr = curr->next;
        }
        return true;
    }
};