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
    ListNode *mergeNodes(ListNode *head)
    {

        ListNode *PrevZero = head;
        ListNode *CurrentZero = head->next;

        while (CurrentZero != nullptr)
        {
            int sum = 0;
            while (CurrentZero != NULL && CurrentZero->val != 0)
            {
                sum += CurrentZero->val;
                CurrentZero = CurrentZero->next;
            }

            PrevZero->val = sum;
            PrevZero->next = CurrentZero;

            if (CurrentZero->next == nullptr)
            {
                PrevZero->next = nullptr;
                break;
            }

            PrevZero = CurrentZero;
            CurrentZero = CurrentZero->next;
        }

        return head;
    }
};