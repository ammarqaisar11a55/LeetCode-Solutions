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

// Approach 1:

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

// Approach 2:

class Solution
{

private:
    ListNode *GetMiddle(ListNode *Head)
    {
        ListNode *Slow = Head;
        ListNode *Fast = Head;

        while (Fast != NULL && Fast->next != NULL)
        {
            Slow = Slow->next;
            Fast = Fast->next->next;
        }

        return Slow;
    }

    ListNode *ReverseLL(ListNode *Head)
    {
        ListNode *Current = Head;
        ListNode *Previous = NULL;
        ListNode *Forward = NULL;

        while (Current != NULL)
        {
            Forward = Current->next;
            Current->next = Previous;
            Previous = Current;
            Current = Forward;
        }

        return Previous;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        if(head==NULL || head->next==NULL)
        return true;

    ListNode* Middle = GetMiddle(head);
    ListNode* SecondHalfStart = ReverseList(Middle);

    ListNode* Head1 = head;
    ListNode* Head2 = SecondHalfStart;

    while(Head2!=NULL)
    {
        if(Head1->val!=Head2->val)
        {
            return false;
        }
        Head1 = Head1 ->next;
        Head2 = Head2 ->next;

        ReverseList(SecondHalfStart);

    }
    return true;
    }
};