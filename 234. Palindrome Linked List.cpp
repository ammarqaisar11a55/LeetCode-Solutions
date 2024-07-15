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
    bool isPalindrome(ListNode *head)
    {

        if (head == NULL)
            return true;

        ListNode *Temp = head;

        vector<int> Nodes;

        while (Temp != NULL)
        {
            Nodes.push_back(Temp->val);
            Temp = Temp->next;
        }

        int st = 0;
        int en = Nodes.size() - 1;

        while (st <= en)
        {
            if (Nodes[st++] != Nodes[en--])
                return false;
        }

        return true;
    }
};