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
    void DFS(TreeNode *root, TreeNode *&Prev, int &MinD)
    {
        if (root == nullptr)
            return;

        DFS(root->left, Prev, MinD);

        if (Prev)
            MinD = min(MinD, abs(root->val - Prev->val));

        Prev = root;

        DFS(root->right, Prev, MinD);
    }

    int getMinimumDifference(TreeNode *root)
    {

        TreeNode *Prev = nullptr;
        int MinD = INT_MAX;
        DFS(root, Prev, MinD);

        return MinD;
    }
};