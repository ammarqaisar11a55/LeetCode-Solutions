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
    void InsertionAtTail(ListNode *&Head, ListNode *&Tail, ListNode *NodeToInsert)
    {
        if (Tail == NULL)
        {
            Tail = NodeToInsert;
            Head = NodeToInsert;
        }
        else
        {
            Tail->next = NodeToInsert;
            Tail = NodeToInsert;
        }
        Tail->next = NULL;
    }

    //***********************************
    void reorderList(ListNode *head)
    {
        vector<ListNode *> Nodes;

        ListNode *Temp = head;

        while (Temp != NULL)
        {
            Nodes.push_back(Temp);
            Temp = Temp->next;
        }

        ListNode *Anshead = NULL;
        ListNode *AnsTail = NULL;

        int s = 0;
        int e = Nodes.size() - 1;

        while (s <= e)
        {
            InsertionAtTail(Anshead, AnsTail, Nodes[s++]);
            InsertionAtTail(Anshead, AnsTail, Nodes[e--]);
        }

        head = Anshead;
    }
};