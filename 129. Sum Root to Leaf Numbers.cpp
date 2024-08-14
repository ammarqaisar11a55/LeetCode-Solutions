/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void DFS(TreeNode *Root, int current, int &total_sum)
    {
        if (Root == NULL)
            return;

        current = current * 10 + Root->val;

        if (Root->left == NULL && Root->right == NULL)
        {
            total_sum += current;
            current /= 10;
        }

        DFS(Root->left, current, total_sum);
        DFS(Root->right, current, total_sum);
    }

    int sumNumbers(TreeNode *root)
    {

        int c = 0;
        int total = 0;

        DFS(root, c, total);

        return total;
    }
};