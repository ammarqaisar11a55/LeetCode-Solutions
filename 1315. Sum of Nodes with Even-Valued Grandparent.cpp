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
    void DFS(TreeNode *root, int parent, int gparent, int &sum)
    {
        if (root == nullptr)
            return;

        if (gparent % 2 == 0)
        {
            sum += root->val;
        }

        DFS(root->left, root->val, parent, sum);
        DFS(root->right, root->val, parent, sum);
    }

    int sumEvenGrandparent(TreeNode *root)
    {

        if (root == nullptr)
            return 0;

        int sum = 0;
        DFS(root, -1, -1, sum);
        return sum;
    }
};