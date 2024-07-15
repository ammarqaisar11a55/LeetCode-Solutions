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

//Approach 1:
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {

        if (head == NULL)
            return NULL;

        vector<int> Nodes;

        ListNode *Temp = head;

        while (Temp != NULL)
        {
            Nodes.push_back(Temp->val);
            Temp = Temp->next;
        }

        reverse(Nodes.begin(), Nodes.end());

        int i = 0;

        ListNode *Temp2 = head;

        while (Temp2 != NULL)
        {
            Temp2->val = Nodes[i++];
            Temp2 = Temp2->next;
        }

        return head;
    }
};

//Approach 2:

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if(head==NULL)
            return NULL;

        ListNode* Prev = NULL;
        ListNode* Current = head;
        ListNode* Forward = Current->next;

        while(Current!=NULL)
        {
            Forward = Current -> next;
            Current -> next = Prev;
            Prev = Current;
            Current = Forward;
        }

        return Prev;
    }
};