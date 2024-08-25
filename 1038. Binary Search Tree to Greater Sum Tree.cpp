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
    void TreeSum(TreeNode *root, int &sum)
    {
        if (root == nullptr)
            return;

        TreeSum(root->right, sum);

        sum += root->val;
        root->val = sum;

        TreeSum(root->left, sum);
    }

    //********************************
    TreeNode *bstToGst(TreeNode *root)
    {

        int sum = 0;
        TreeSum(root, sum);
        return root;
    }
};