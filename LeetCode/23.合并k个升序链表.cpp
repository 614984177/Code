#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */

// @lc code=start
// 
// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
private:
    struct cmp 
    {
        bool operator () (ListNode *a, ListNode *b) const 
        {
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for (int i = 0; i < lists.size(); i++) { 
            if (lists[i]) q.push(lists[i]);
        }
        while (!q.empty()) {
            ListNode* t = q.top(); q.pop();
            cur->next = t;
            cur = cur->next;
            if (t->next) q.push(t->next);
        }
        return head->next;
    }
};
// @lc code=end

