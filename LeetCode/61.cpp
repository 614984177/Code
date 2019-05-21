/**
 * Definition for singly-linked list.
 * struct ListNode 
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (head == nullptr) return head;
        ListNode *tail = head, *cur = head;
        int len = 1;
        while (tail->next != nullptr) tail = tail->next, len++;
        k %= len; k = len - k - 1;
        while (k--) cur = cur->next;
        tail->next = head;
        head = cur->next;
        cur->next = nullptr;
        return head;
    }
};