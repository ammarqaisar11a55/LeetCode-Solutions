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
    ListNode *detectCycle(ListNode *head)
    {

        if (head == NULL)
            return NULL;
        ListNode *Intersection = FloydCycleDetection(head);

        if (Intersection == NULL)
            return NULL;

        ListNode *Slow = head;

        while (Slow != Intersection)
        {
            Slow = Slow->next;
            Intersection = Intersection->next;
        }

        return Slow;
    }

    ListNode *FloydCycleDetection(ListNode *Head)
    {
        if (Head == NULL)
            return NULL;

        ListNode *Slow = Head;
        ListNode *Fast = Head;

        while (Fast != NULL && Fast->next != NULL)
        {
            Slow = Slow->next;
            Fast = Fast->next->next;
            if (Slow == Fast)
            {
                return Slow;
            }
        }

        return NULL;
    }
};