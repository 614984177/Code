/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    ListNode* findMiddle(ListNode *head) {
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
            head = head->next;
            fast = fast->next->next;
        }
        return head;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr;
        while (head) {
            ListNode *next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }

    void reorderList(ListNode* head) {
        ListNode *mid = findMiddle(head);
        ListNode *headA = head, *headB = reverseList(mid->next);
        mid->next = nullptr;
        while (headA && headB) {
            ListNode *next1 = headA->next, *next2 = headB->next;
            headA->next = headB;
            headA = next1;
            headB->next = next1;
            headB = next2;
        }
    }
};
// @lc code=end

