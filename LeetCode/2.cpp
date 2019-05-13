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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
        int g = 0;
        while (l1 != nullptr || l2 != nullptr || g)
        {
            int x = g;
            if (l1 != nullptr) x += l1->val, l1 = l1->next;
            if (l2 != nullptr) x += l2->val, l2 = l2->next;
            cur->next = new ListNode(x % 10);
            cur = cur->next;
            g = x / 10;
        }
        return head->next;
    }
};