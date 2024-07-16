/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {

        if (head == NULL)
            return NULL;

        ListNode *Previous = NULL;
        ListNode *Current = head;
        int target = val;

        while (Current != NULL)
        {
            if (Current->val == target)
            {
                if (Previous == NULL)
                {
                    head = Current->next;
                }
                else
                {
                    Previous->next = Current->next;
                }
                Current = Current->next;
            }
            else
            {
                Previous = Current;
                Current = Current->next;
            }
        }
        return head;
    }
};