#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start

// Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* next;
//     Node* random;
    
//     Node(int _val) {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        Node *cur = head;
        while (cur) {
            Node *newNode = new Node(cur->val);
            newNode->next = cur->next;
            cur->next = newNode;
            cur = cur->next->next;
        }
        cur = head;
        while (cur) {
            Node *newNode = cur->next;
            if (cur->random) newNode->random = cur->random->next;
            cur = cur->next->next;
        }
        Node *headNew = head->next;
        cur = head;
        while (cur) {
            Node *newNode = cur->next;
            cur->next = cur->next->next;
            newNode->next = newNode->next == nullptr ? nullptr : newNode->next->next;
            cur = cur->next;
        }
        return headNew;
    }
};
// @lc code=end

