#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
struct Node
{
    int key, value;
    Node *prev_, *next_;
    Node(): key(0), value(0), prev_(nullptr), next_(nullptr) {}
    Node(int key_, int value_) : key(key_), value(value_), prev_(nullptr), next_(nullptr) {}
};

class LRUCache {
private:
    int capacity, size;
    Node *head, *tail;
    unordered_map<int, Node*> cache;
public:
    LRUCache(int capacity_) {
        capacity = capacity_;
        size = 0;
        head = new Node();
        tail = new Node();
        head->next_ = tail;
        tail->prev_ = head;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        Node* n = cache[key];
        moveToHead(n);
        return n->value;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key]->value = value;
            moveToHead(cache[key]);
            return ;
        }
        Node *new_ = new Node(key, value);
        addToHead(new_);
        cache[key] = new_;
        size++;
        if (size > capacity) {
            Node* end_ = tail->prev_;
            removeNode(end_);
            cache.erase(end_->key);
            delete end_;
            size--;
        }
    }

    void addToHead(Node *n) {
        n->next_ = head->next_;
        n->prev_ = head;
        head->next_->prev_ = n;
        head->next_ = n;
    }

    void removeNode(Node *n) {
        n->prev_->next_ = n->next_;
        n->next_->prev_ = n->prev_;
    }

    void moveToHead(Node *n) {
        removeNode(n);
        addToHead(n);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main() {

    return 0;
}