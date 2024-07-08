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
    int getDecimalValue(ListNode *head)
    {

        vector<int> N;

        while (head != NULL)
        {
            N.push_back(head->val);
            head = head->next;
        }

        if (N.size() == 0)
            return N[0];

        int ans = 0;
        int j = 0;

        for (int i = N.size() - 1; i >= 0; i--)
        {
            ans += N[i] * pow(2, j++);
        }

        return ans;
    }
};