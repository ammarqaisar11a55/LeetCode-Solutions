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
    int GetListLength(ListNode *Head)
    {
        int length = 0;

        while (Head != NULL)
        {
            length++;
            Head = Head->next;
        }

        return length;
    }
    //****************************************************************
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        int list1length = GetListLength(headA);
        int list2length = GetListLength(headB);

        ListNode *ptr1;
        ListNode *ptr2;

        if (list1length == list2length)
        {
            ptr1 = headA;
            ptr2 = headB;

            while (ptr1 != NULL && ptr2 != NULL)
            {
                if (ptr1 == ptr2)
                    return ptr1;

                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
        }
        else if (list1length > list2length)
        {
            int diff = list1length - list2length;
            ptr1 = headA;

            while (diff != 0)
            {
                ptr1 = ptr1->next;
                diff--;
            }

            ptr2 = headB;

            while (ptr1 != NULL && ptr2 != NULL)
            {
                if (ptr1 == ptr2)
                    return ptr1;

                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
        }
        else
        {
            int diff = list2length - list1length;

            ptr1 = headB;

            while (diff != 0)
            {
                ptr1 = ptr1->next;
                diff--;
            }

            ptr2 = headA;

            while (ptr1 != NULL && ptr2 != NULL)
            {
                if (ptr1 == ptr2)
                    return ptr1;

                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
        }

        return NULL;
    }
};