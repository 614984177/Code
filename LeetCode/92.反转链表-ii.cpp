/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy  = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy;
        right -= left;
        while (--left) pre = pre->next;
        ListNode *cur = pre->next;
        while (right--) {
            ListNode *move = cur->next;
            cur->next = cur->next->next;
            move->next = pre->next;
            pre->next = move;
        }
        return dummy->next;
    }
};
// @lc code=end

