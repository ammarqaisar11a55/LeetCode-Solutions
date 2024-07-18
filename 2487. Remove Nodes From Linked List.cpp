
class Solution
{
public:

    //This function is used to Create new Answer list:
    void InsertAtTail(ListNode *&Head, int data)
    {
        ListNode *NodeToInsert = new ListNode(data);

        if (Head == NULL)
        {
            Head = NodeToInsert;
        }
        else
        {
            NodeToInsert->next = Head;
            Head = NodeToInsert;
        }
    }


    //************************************
    ListNode *removeNodes(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        vector<int> Nodes;

        ListNode *Temp = head;

        while (Temp != NULL)
        {
            if (Nodes.empty())
            {
                Nodes.push_back(Temp->val);
                Temp = Temp->next;
                continue;
            }

            while (!Nodes.empty() && (Temp->val > Nodes.back()))
            {
                Nodes.pop_back();
            }

            Nodes.push_back(Temp->val);
            Temp = Temp->next;
        }

        ListNode *Ans = NULL;

        reverse(Nodes.begin(), Nodes.end());

        for (int i = 0; i < Nodes.size(); i++)
        {
            InsertAtTail(Ans, Nodes[i]);
        }
        return Ans;
    }
};