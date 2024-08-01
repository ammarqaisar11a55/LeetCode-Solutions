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
    void InsertAtTail(ListNode *&Head, ListNode *&Tail, ListNode *NodeToInsert)
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

    //******************************************
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        vector<ListNode *> Nodes;

        while (head != NULL)
        {
            Nodes.push_back(head);
            head = head->next;
        }

        ListNode *AnsHead = NULL;
        ListNode *AnsTail = NULL;

        for (int i = 0; i < Nodes.size(); i++)
        {
            if (Nodes.size() - n != i)
            {
                InsertAtTail(AnsHead, AnsTail, Nodes[i]);
            }
        }
        return AnsHead;
    }
};