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
    void PreOrder(TreeNode *root, int target, TreeNode *&Ans)
    {
        if (root == NULL)
            return;

        if (root->val == target)
        {
            Ans = root;
            return;
        }

        PreOrder(root->left, target, Ans);
        PreOrder(root->right, target, Ans);
    }

    TreeNode *searchBST(TreeNode *root, int val)
    {

        TreeNode *Ans = NULL;
        PreOrder(root, val, Ans);
        return Ans;
    }
};