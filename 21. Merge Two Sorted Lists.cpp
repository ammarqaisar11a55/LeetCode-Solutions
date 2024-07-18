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
    ListNode *Ans(ListNode *list1, ListNode *list2)
    {
        if (list1->next == NULL)
        {
            list1->next = list2;
            return list1;
        }

        ListNode *Current1 = list1;
        ListNode *Forward1 = Current1->next;

        ListNode *Current2 = list2;
        ListNode *Forward2 = NULL;

        while (Forward1 != NULL && Current2 != NULL)
        {
            if ((Current2->val >= Current1->val) && (Current2->val <= Forward1->val))
            {
                // Insertion of Node:
                Forward1 = Current1->next;
                Forward2 = Current2->next;
                Current1->next = Current2;
                Current2->next = Forward1;

                // Updating Pointers:
                Current1 = Current2;
                Current2 = Forward2;
            }
            else
            {
                Current1 = Forward1;
                Forward1 = Forward1->next;

                if (Forward1 == NULL)
                {
                    Current1->next = Current2;
                    return list1;
                }
            }
        }
        return list1;
    }
    //**********************************************
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        if (list1 == NULL)
            return list2;

        if (list2 == NULL)
            return list1;

        if (list1 == NULL && list2 == NULL)
            return NULL;

        if (list1->val <= list2->val)
            return Ans(list1, list2);

        else
            return Ans(list2, list1);
    }
};