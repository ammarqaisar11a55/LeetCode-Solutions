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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {

        int current = 1;
        ListNode *FromA = list1;
        ListNode *ToB = list1;
        ListNode *List2End = list2;

        for (int i = 1; i < a; i++)
        {
            FromA = FromA->next;
        }

        for (int i = 1; i <= b; i++)
        {
            ToB = ToB->next;
        }

        while (List2End->next != NULL)
        {
            List2End = List2End->next;
        }

        FromA->next = list2;
        List2End->next = ToB->next;

        return list1;
    }
};