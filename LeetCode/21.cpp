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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
        while (l1 != nullptr || l2 != nullptr)
        {
            cur->next = new ListNode(-1);
            cur = cur->next;
            if (l1 != nullptr && l2 != nullptr)
            {
                if (l1->val <= l2->val) cur->val = l1->val, l1 = l1->next;
                else cur->val = l2->val, l2 = l2->next;
            }
            else if (l1 != nullptr) cur->val = l1->val, l1 = l1->next;
            else if (l2 != nullptr) cur->val = l2->val, l2 = l2->next;
        }
        return head->next;
    }
};