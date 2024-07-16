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
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {

        unordered_set<int> TobeRemoved;

        for (int x : nums)
            TobeRemoved.insert(x);

        ListNode *Current = head;
        ListNode *Previous = NULL;

        while (Current != NULL)
        {
            if (TobeRemoved.find(Current->val) != TobeRemoved.end())
            {
                if (Previous == NULL)
                {
                    head = Current->next;
                }
                else
                {
                    Previous->next = Current->next;
                }
                Current = Current->next;
            }
            else
            {
                Previous = Current;
                Current = Current->next;
            }
        }

        return head;
    }
};