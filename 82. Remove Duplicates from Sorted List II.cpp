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
    void InsertAtTail(ListNode *&head, ListNode *&tail, int data)
    {
        ListNode *NodeToInsert = new ListNode(data);

        if (tail == nullptr)
        {
            head = NodeToInsert;
            tail = NodeToInsert;
        }
        else
        {
            tail->next = NodeToInsert;
            tail = NodeToInsert;
        }
    }
    //***************************************
    ListNode *deleteDuplicates(ListNode *head)
    {

        unordered_map<int, int> counts;

        ListNode *Temp = head;

        while (Temp != NULL)
        {
            counts[Temp->val]++;
            Temp = Temp->next;
        }

        ListNode *AnsHead = NULL;
        ListNode *AnsTail = NULL;

        Temp = head;

        while (Temp != NULL)
        {
            if (counts[Temp->val] == 1)
                InsertAtTail(AnsHead, AnsTail, Temp->val);

            Temp = Temp->next;
        }

        return AnsHead;
    }
};