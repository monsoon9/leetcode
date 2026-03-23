#include<iostream>
using namespace std;
#include<vector>


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


//使用hash存储
#include<unordered_map>
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;

        //建立新数组连接
        Node* curr = head;
        while(curr!=nullptr){
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        //建立新数组的next和random
        curr = head;
        while(curr!=nullptr){
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            curr = curr->next;          
        }
        return mp[head];
    }
};




//直接原地复制修改
/*第一步：复制节点并插入
在每个原节点后面紧跟一个复制节点。

原链表：A -> B -> C

插入后：A -> A' -> B -> B' -> C -> C'

第二步：复制随机指针这是最巧妙的一步。由于 $A'$ 就在 $A$ 后面，
那么 $A'$ 的 random 应该指向 $A \to random \to next$。
即：curr->next->random = curr->random->next（需注意空指针）。

第三步：拆分链表
将原链表和复制链表拆分开，恢复原链表，并返回复制链表的头节点。*/


class Solution {
public:
    Node* copyRandomList(Node* head) {
        //判空数组
        if(head==nullptr)return nullptr;
        //复制数组
        Node* curr = head;
        while(curr!=nullptr){
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        //复制random指针
        curr = head;
        while(curr!=nullptr){
            if(curr->random!=nullptr){
                curr->next->random = curr->random->next;//这里是random->next 因为要指向克隆结点
            }
            curr = curr->next->next;
        }

        //拆分链表
        Node* newHead = head->next;
        curr = head;
        while(curr!=nullptr){
            Node* copy = curr->next;
            curr->next = copy->next;//恢复原链表
            if(copy->next!=nullptr){
                copy->next = copy->next->next;
            }
            curr = curr->next;
        }
        return newHead;
    }
};