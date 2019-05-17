struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
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
    struct cmp 
    {
        bool operator () (ListNode *a, ListNode *b) const 
        {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] == nullptr) continue;
            pq.push(lists[i]);
        }
        while (!pq.empty())
        {
            ListNode *u = pq.top(); pq.pop();
            cur->next = u; // cur->next = new ListNode(u->val); 每次开结点会比较慢
            cur = cur->next; 
            u = u->next;
            if (u != nullptr) pq.push(u);
        }
        return head->next;
    }
};