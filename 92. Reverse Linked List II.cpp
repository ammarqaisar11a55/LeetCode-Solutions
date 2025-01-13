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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {

        if (left == right || head == nullptr)
            return head;

        ListNode *Left_Pointer = head;
        ListNode *Right_Pointer = head;

        ListNode *Left_Pointer_Prev = nullptr;
        ListNode *Right_Pointer_Forward = nullptr;

        // while (left - 1 > 0)
        // {
        //     Left_Pointer_Prev = Left_Pointer;

        //     Left_Pointer = Left_Pointer->next;
        //     Right_Pointer = Right_Pointer->next;

        //     left--;
        //     right--;
        // }

        for (int i = 1; i < left; i++)
        {
            Left_Pointer_Prev = Left_Pointer;
            Left_Pointer = Left_Pointer->next;
        }

        // while (right - 1 > 0)
        // {
        //     Right_Pointer = Right_Pointer->next;
        //     Right_Pointer_Forward = Right_Pointer->next;
        //     right--;
        // }

        for (int i = 1; i < right; i++)
        {
            Right_Pointer = Right_Pointer->next;
        }

        Right_Pointer_Forward = Right_Pointer->next;

        if (Left_Pointer_Prev != nullptr)
        {
            Left_Pointer_Prev->next = nullptr;
        }

        Right_Pointer->next = nullptr;

        ListNode *Current = Left_Pointer;
        ListNode *Forward = nullptr;
        ListNode *Previous = nullptr;

        while (Current != nullptr)
        {
            Forward = Current->next;
            Current->next = Previous;
            Previous = Current;
            Current = Forward;
        }

        if (Left_Pointer_Prev != nullptr)
        {
            Left_Pointer_Prev->next = Previous;
        }
        else
        {
            head = Previous;
        }

        Left_Pointer->next = Right_Pointer_Forward;

        // cout << "Left Prev: " << Left_Pointer_Prev->val << endl;
        // cout << "Left: " << Left_Pointer->val << endl;

        // cout << "Right: " << Left_Pointer->val << endl;
        // cout << "Right Forward: " << Right_Pointer_Forward->val << endl;

        return head;
    }
};