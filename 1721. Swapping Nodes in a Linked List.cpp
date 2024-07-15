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
    ListNode *swapNodes(ListNode *head, int k)
    {

        vector<int> Nodes;

        ListNode *Temp = head;

        while (Temp != NULL)
        {
            Nodes.push_back(Temp->val);
            Temp = Temp->next;
        }

        swap(Nodes[k - 1], Nodes[Nodes.size() - k]);

        Temp = head;
        int j = 0;

        while (Temp != NULL)
        {
            Temp->val = Nodes[j++];
            Temp = Temp->next;
        }

        return head;
    }
};