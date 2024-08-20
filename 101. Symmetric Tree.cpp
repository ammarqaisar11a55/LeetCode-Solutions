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
    void DFS(TreeNode *leftN, TreeNode *rightN, bool &ans)
    {
        if (leftN == NULL && rightN == NULL)
        {
            return;
        }

        if (leftN == NULL || rightN == NULL || leftN->val != rightN->val)
        {
            ans = false;
            return;
        }

        DFS(leftN->right, rightN->left, ans);
        DFS(leftN->left, rightN->right, ans);
    }

    bool isSymmetric(TreeNode *root)
    {

        if (root == NULL)
            return true;

        bool ans = true;
        DFS(root->left, root->right, ans);
        return ans;
    }
};