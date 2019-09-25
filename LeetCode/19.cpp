class Solution 
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *cur = new ListNode(-1);
        cur->next = head;
        ListNode *fast = cur, *slow = cur;
        for(int i = 0; i <= n; i++) 
            fast = fast->next;
        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *p = slow->next;
        slow->next = slow->next->next;
        delete p;
        return cur->next;
    }
};