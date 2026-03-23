#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0),next(nullptr) {}
    ListNode(int x) : val(x),next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x),next(next) {} 
};

// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         ListNode* res;
        
//         ListNode* p1 = list1;
//         ListNode* p2 = list2;

//         // if(list1->val > list2->val){
//         //     res = list2;
//         //     list2=list2->next;
//         // }else{
//         //     res = list1;
//         //     list1=list1->next;
//         // }
//         while(p1!=nullptr&&p2!=nullptr){
//             if(p1->val > p2->val){
//             res->next = new ListNode(p2->val);
//             p2=p2->next;
//             }else{
//             res->next = new ListNode(p1->val);
//             p1=p1->next;
//             }
//         }
//         if(p1==nullptr){
//             while(p2!=nullptr)res->next = new ListNode(p2->val);
//         }else{
//             while(p1!=nullptr)res->next = new ListNode(p1->val);
//         }

//         return res->next;
//     }
// };



class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 1. 创建一个哨兵节点（假头），这样不用单独处理返回值的头部
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        // 2. 像拉拉链一样对比
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                curr->next = list1;  // 直接把原来的节点接过来
                list1 = list1->next; // 移动 list1
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;       // 别忘了移动合并链表的指针
        }

        // 3. 处理剩余部分：如果有一个链表还没走完，直接把剩下的整段接上去
        // 链表的优势就在这里，不需要写 while 循环一个个接
        curr->next = (list1 != nullptr) ? list1 : list2;

        // 4. 返回哨兵节点的下一个，也就是真正的头
        ListNode* res = dummy->next;
        delete dummy; // 良好的习惯：释放哨兵节点内存
        return res;
    }
};