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
    bool preorder(TreeNode *root, int rootval)
    {
        if (root == NULL)
            return true;

        if (rootval != root->val)
            return false;

        return preorder(root->right, rootval) && preorder(root->left, rootval);
    }

    //***********************************
    bool isUnivalTree(TreeNode *root)
    {

        int rootval = root->val;

        return preorder(root, rootval);
    }
};