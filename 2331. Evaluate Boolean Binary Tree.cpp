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
    bool evaluateTree(TreeNode *root)
    {

        if (root->left == NULL && root->right == NULL)
            return root->val;

        bool leftval = evaluateTree(root->left);
        bool rightval = evaluateTree(root->right);

        bool ans;

        if (root->val == 2)
        {
            ans = leftval || rightval;
        }
        else if (root->val == 3)
        {
            ans = leftval && rightval;
        }

        return ans;
    }
};