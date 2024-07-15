/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {

        ListNode *Slow = head;
        ListNode *Fast = head;

        while (Fast != NULL && Fast->next != NULL)
        {
            Slow = Slow->next;
            Fast = Fast->next->next;

            if (Fast == Slow)
                return true;
        }

        return false;
    }
};