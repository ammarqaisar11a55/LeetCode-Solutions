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
    int dfs(TreeNode *root, bool &ans)
    {
        if (root == nullptr)
            return 0;

        int L_height = dfs(root->left, ans);
        int R_height = dfs(root->right, ans);

        if (abs(L_height - R_height) > 1)
        {
            ans = false;
        }

        return max(L_height, R_height) + 1;
    }

    bool isBalanced(TreeNode *root)
    {
        bool ans = true;
        dfs(root, ans);
        return ans == true ? true : false;
    }
};