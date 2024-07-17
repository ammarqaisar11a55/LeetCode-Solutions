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
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        // Case if the list is empty or the size of list is 1

    if(head==NULL || head->next==NULL)
        return head;

  //  vector<int>GCD;

    ListNode* CurrentNode = head;

    // while(CurrentNode->next!=NULL)
    // {
    //     GCD.push_back(__gcd(CurrentNode->val,CurrentNode->next->val));
    //     CurrentNode = CurrentNode ->next;
    // }

    CurrentNode = head;
    ListNode* Forward = NULL;

    while(CurrentNode ->next!=NULL)
    {
        int gcd = __gcd(CurrentNode->val,CurrentNode->next->val);

        Forward = CurrentNode->next;
        ListNode* NodeToInsert = new ListNode(gcd);
        CurrentNode -> next = NodeToInsert;
        NodeToInsert ->next = Forward;
        CurrentNode = Forward;
    }

    return head;
        
    }
};