#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start

// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *hair = new ListNode(), *pre, *next_, *tail;
        hair->next = head;
        pre = hair;
        next_ = nullptr;
        while (head) {
            tail = pre;
            for (int i = 0; i < k; i++) {
                if (tail->next == nullptr) return hair->next;
                tail = tail->next;
            }
            next_ = tail->next;
            tie(head, tail) = reverseList(head, tail);
            pre->next = head;
            tail->next = next_;
            pre = tail;
            head = next_;
        }
        return hair->next;
    }

    pair<ListNode*, ListNode*> reverseList(ListNode* head, ListNode* tail) {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (pre != tail) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return {tail, head};
    }
};
// @lc code=end
