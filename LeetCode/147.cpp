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
    ListNode* insertionSortList(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *slow = head, *fast = head->next;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        return merge(insertionSortList(head), insertionSortList(fast));
    }
    ListNode* merge(ListNode* a, ListNode* b)
    {
        ListNode head(-1);
        ListNode *cur = &head;
        while (a != nullptr && b != nullptr)
        {
            if (a->val < b->val) cur->next = a, a = a->next;
            else cur->next = b, b = b->next;
            cur = cur->next;
        }
        if (a != nullptr) cur->next = a;
        if (b != nullptr) cur->next = b;
        return head.next;
    }
};