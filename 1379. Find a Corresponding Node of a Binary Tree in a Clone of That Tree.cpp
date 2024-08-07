/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *ANS;

    void Inorder(TreeNode *croot, TreeNode *Target)
    {
        if (croot == NULL)
            return;

        Inorder(croot->left, Target);

        if (croot->val == Target->val)
        {
            ANS = croot;
            return;
        }

        Inorder(croot->right, Target);
    }

    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {

        Inorder(cloned, target);

        return ANS;
    }
};