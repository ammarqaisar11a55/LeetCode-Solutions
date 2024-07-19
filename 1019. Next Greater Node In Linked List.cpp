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
    vector<int> nextLargerNodes(ListNode *head)
    {

        ListNode *Temp = head;
        vector<int> Nodes;

        while (Temp != NULL)
        {
            Nodes.push_back(Temp->val);
            Temp = Temp->next;
        }

        vector<int> Ans;

        for (int i = 0; i < Nodes.size(); i++)
        {
            int NextGreatorFor = Nodes[i];
            int j = i;

            while (j < Nodes.size())
            {
                if (Nodes[j] > NextGreatorFor)
                {
                    NextGreatorFor = Nodes[j];
                    break;
                }
                j++;
            }
            Ans.push_back(NextGreatorFor == Nodes[i] ? 0 : NextGreatorFor);
        }

        return Ans;
    }
};