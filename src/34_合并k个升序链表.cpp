#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> memo;
        for(auto a:lists){
            while(a!=nullptr){
                memo.push_back(a->val);
                a = a->next;
            }
        }
        sort(memo.begin(),memo.end());

        ListNode* newHead = new ListNode(0);
        ListNode* curr = newHead;

        for(auto val:memo){
            curr->next = new ListNode(val);
            curr = curr->next;
        }

        return newHead->next;
    }
};

#include<queue>

//利用小顶堆
class Solution{

    // 自定义比较器：因为我们需要小顶堆，所以 val 大的优先级反而低
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;

        //初始化把所有链表的头节点放进去
        for(auto head : lists){
            if(head)pq.push(head);
        }

        //使用哑结点
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        //开始合并
        while(!pq.empty()){
            //取出最小结点
            ListNode* s = pq.top();
            pq.pop();

            curr->next = s;
            curr = curr->next;

            if(s->next)pq.push(s->next);

        }
        return dummy->next;
    }
};



//小顶堆1
class Solution{
public:

struct compare{
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;

        //先将所有链表的头节点放入到pq中
        for(auto list:lists){
            if(list)pq.push(list);
        }

        //使用哑结点
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        //开始建立新链表
        while(!pq.empty()){
            ListNode* newNode = pq.top();
            pq.pop();
            int newOne = newNode->val;
            if(newNode->next)pq.push(newNode->next);

            curr->next = new ListNode(newOne);
            curr = curr->next;
        }
        return dummy->next;
    }
};