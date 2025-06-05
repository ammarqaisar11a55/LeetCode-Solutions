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
    int numComponents(ListNode* head, vector<int>& nums) {
        int res = 0;
        unordered_set<int> st(nums.begin(), nums.end());
        int current_connected_nodes = 0;

        while (head != NULL) {
            if (st.find(head->val) != st.end()) {
                current_connected_nodes++;
            } else {
                if (current_connected_nodes > 0)
                    res++;
                current_connected_nodes = 0;
            }

            head = head->next;
        }

        if (current_connected_nodes > 0)
            res++;

        return res;
    }
};
