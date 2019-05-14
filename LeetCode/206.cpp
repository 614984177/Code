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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode *headA = new ListNode(-1);
        ListNode *p = head;
        while (p != nullptr)
        {
            ListNode *t = new ListNode(p->val);
            t->next = headA->next;
            headA->next = t;
            p = p->next;
        }
        return headA->next;
    }
};