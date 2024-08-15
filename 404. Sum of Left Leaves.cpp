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
    void DFS(TreeNode *root, int &ANS, bool isleft = false)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL && isleft == true)
            ANS += root->val;

        DFS(root->left, ANS, true);
        DFS(root->right, ANS, false);
    }

    int sumOfLeftLeaves(TreeNode *root)
    {

        int Ans = 0;
        DFS(root, Ans);
        return Ans;
    }
};