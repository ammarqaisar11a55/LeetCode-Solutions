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
    void insertionAtTail(ListNode *&head, ListNode *&Tail, ListNode *NodeToInsert)
    {
        if (Tail == NULL)
        {
            Tail = NodeToInsert;
            head = NodeToInsert;
        }
        else
        {
            Tail->next = NodeToInsert;
            Tail = NodeToInsert;
        }

        Tail->next = NULL;
    }

    //********************************************
    ListNode *rotateRight(ListNode *head, int k)
    {

        vector<ListNode *> Nodes;

        ListNode *Temp = head;

        while (Temp != NULL)
        {
            Nodes.push_back(Temp);
            Temp = Temp->next;
        }

        vector<ListNode *> RotatedNodes(Nodes.size());

        for (int i = 0; i < Nodes.size(); i++)
        {
            RotatedNodes[(i + k) % Nodes.size()] = Nodes[i];
        }

        ListNode *AnsHead = NULL;
        ListNode *AnsTail = NULL;

        for (int i = 0; i < RotatedNodes.size(); i++)
        {
            insertionAtTail(AnsHead, AnsTail, RotatedNodes[i]);
        }

        return AnsHead;
    }
};