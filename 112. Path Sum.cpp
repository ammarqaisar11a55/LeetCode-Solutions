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
    void INORDER(TreeNode *Root, int sum, bool &found)
    {
        // LEFT , ROOT , RIGHT
        if (Root == NULL)
        {
            return;
        }

        sum -= Root->val;

        if (Root->left == NULL && Root->right == NULL && sum == 0)
        {
            found = true;
            return;
        }

        INORDER(Root->left, sum, found);
        INORDER(Root->right, sum, found);
    }
    //*****************

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
            return false;

        bool found = false;
        INORDER(root, targetSum, found);
        return found;
    }
};