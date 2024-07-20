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
    void InsertionAtTail(ListNode *&Head, ListNode *&Tail, int data)
    {
        if (Tail == NULL)
        {
            ListNode *Node = new ListNode(data);
            Tail = Node;
            Head = Node;
        }
        else
        {
            ListNode *Node = new ListNode(data);
            Tail->next = Node;
            Tail = Node;
        }
    }
    //*******************************************
    ListNode *ReverseLinkedList(ListNode *Head)
    {
        ListNode *Current = Head;
        ListNode *Previous = NULL;
        ListNode *Forward = NULL;

        while (Current != NULL)
        {
            Forward = Current->next;
            Current->next = Previous;
            Previous = Current;
            Current = Forward;
        }

        Head = Previous;
        return Previous;
    }

    //*************************************************
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        int carry = 0;
        ListNode *head = NULL;
        ListNode *tail = NULL;

        while (l1 != NULL || l2 != NULL || carry != 0)
        {
            int valofl1 = 0;
            if (l1 != NULL)
                valofl1 = l1->val;

            int valofl2 = 0;
            if (l2 != NULL)
                valofl2 = l2->val;

            int sum = carry + valofl1 + valofl2;

            InsertionAtTail(head, tail, sum % 10);

            carry = sum / 10;

            if (l1 != NULL)
                l1 = l1->next;

            if (l2 != NULL)
                l2 = l2->next;
        }

        return head;
    }
};