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
    void DFS(TreeNode *root, TreeNode *&prev, int &mini)
    {
        if (root == nullptr)
            return;

        DFS(root->left, prev, mini);

        if (prev)
            mini = min(mini, root->val - prev->val);

        prev = root;

        DFS(root->right, prev, mini);
    }

    int minDiffInBST(TreeNode *root)
    {

        TreeNode *prev = nullptr;
        int mini = INT_MAX;

        DFS(root, prev, mini);

        return mini;
    }
};