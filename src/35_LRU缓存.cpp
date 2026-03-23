#include<iostream>
using namespace std;
#include<vector>
#include<list>
#include<unordered_map>


class LRUCache {
private:
    int cap;
    list<pair<int,int>> cache;
    //哈希表的 Value 应该存的是指向链表节点的迭代器 (iterator)，而不是整个链表。如果是存整个链表，每次查询都会拷贝一份链表，失去 $O(1)$ 的意义。
    unordered_map<int,list<pair<int,int>>::iterator> map;


public:
    LRUCache(int capacity) : cap(capacity) {
        
    }
    
    int get(int key) {
        if(map.find(key)==map.end())return -1;
        // 如果存在，先将该节点移动到链表头部（表示最近使用）
        // splice 是 list 的高效操作，可以在 O(1) 内移动节点
        cache.splice(cache.begin(),cache,map[key]);
        return map[key]->second;
    }
    
    void put(int key, int value) {
        //cache中有key 提到最前面
        if(map.find(key)!=map.end()){
            map[key]->second = value;
            cache.splice(cache.begin(),cache,map[key]);
        }else{//如果不存在
            if(cache.size()==cap){
                //如果cache满了，删除链表末尾
                int deleteKey = cache.back().first;
                map.erase(deleteKey);
                cache.pop_back();
            }
            //插入新结点到cache
            cache.push_front({key,value});
            map[key] = cache.begin();
        }
    }
};
