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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));

        int left_col = 0, right_col = n - 1, upper_row = 0, lower_row = m - 1;

        while (head != NULL) {
            int temp = left_col;

            // Upper Row:
            while (temp <= right_col && head != NULL) {
                res[upper_row][temp] = head->val;
                temp++;

                head = head->next;
            }
            upper_row++;

            temp = upper_row;

            // Right Col:
            while (temp <= lower_row && head != NULL) {
                res[temp][right_col] = head->val;
                temp++;
                head = head->next;
            }
            right_col--;

            temp = right_col;

            // Lower_Row:
            while (temp >= left_col && head != NULL) {
                res[lower_row][temp] = head->val;
                temp--;
                head = head->next;
            }
            lower_row--;

            temp = lower_row;

            // Left Col:
            while (temp >= upper_row && head != NULL) {
                res[temp][left_col] = head->val;
                temp--;
                head = head->next;
            }

            left_col++;
        }

        return res;
    }
};
