#include<iostream>
using namespace std;


struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0),next(nullptr) {}
    ListNode(int x) : val(x),next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x),next(next) {} 
};

/*设：从头节点到环入口的距离为 $a$。从环入口到相遇点的距离为 $b$。从相遇点再走回到环入口的距离为 $c$。当快慢指针相遇时：慢指针走过的路程：$S_{slow} = a + b$快指针走过的路程：$S_{fast} = a + n(b + c) + b$ （$n$ 为快指针在环里转的圈数）因为快指针速度是慢指针的两倍，所以：$$2(a + b) = a + n(b + c) + b$$化简得：$$a = (n-1)(b+c) + c$$结论：从头节点出发到入口的距离 $a$，等于从相遇点继续走 $c$ 距离（再加上若干圈）。这意味着：只要让一个指针从头开始走，另一个指针从相遇点开始走，它们速度一样，最终一定会在入口处相遇。*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;

        // 第一步：利用快慢指针寻找相遇点
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            // 发现有环，开始寻找入口
            if (slow == fast) {
                // 让其中一个指针回到头节点
                ListNode *index1 = head;
                ListNode *index2 = fast; // 此时 fast 在相遇点

                // 第二步：两个指针以相同速度（1步/次）前进
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                // 再次相遇的地方就是入口
                return index1;
            }
        }

        // 无环返回 null
        return nullptr;
    }
};