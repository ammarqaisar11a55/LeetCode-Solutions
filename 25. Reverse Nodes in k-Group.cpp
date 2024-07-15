
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        if (head == NULL)
            return NULL;

        ListNode *Temp = head;

        for (int i = 0; i < k; i++)
        {
            if (Temp == NULL)
                return head;
            Temp = Temp->next;
        }

        int count = 0;
        ListNode *CurrentNode = head;
        ListNode *PreviousNode = NULL;
        ListNode *NextNode = NULL;

        while (CurrentNode != NULL && count < k)
        {
            NextNode = CurrentNode->next;
            CurrentNode->next = PreviousNode;
            PreviousNode = CurrentNode;
            CurrentNode = NextNode;
            count++;
        }

        if (NextNode != NULL)
        {
            head->next = reverseKGroup(NextNode, k);
        }

        return PreviousNode;
    }
};