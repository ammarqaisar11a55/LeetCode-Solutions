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
    void DFS(TreeNode *root, int val, int depth, int tdepth)
    {
        if (root == nullptr)
            return;

        if (tdepth == depth - 1)
        {
            TreeNode *templeft = root->left;
            TreeNode *tempright = root->right;

            TreeNode *Nleft = new TreeNode(val);
            TreeNode *Nright = new TreeNode(val);

            root->left = Nleft;
            root->right = Nright;

            Nleft->left = templeft;
            Nright->right = tempright;

            return;
        }

        DFS(root->left, val, depth, tdepth + 1);
        DFS(root->right, val, depth, tdepth + 1);
    }

    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {

        if (depth == 1)
        {
            TreeNode *root2 = new TreeNode(val);
            root2->left = root;
            return root2;
        }

        DFS(root, val, depth, 1);
        return root;
    }
};