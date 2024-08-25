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
    void DFS(TreeNode *root, TreeNode *&parent, int x, int &final_depth, int temp_depth)
    {
        if (root == nullptr)
        {
            return;
        }

        if (root->left != nullptr && root->left->val == x)
        {
            final_depth = temp_depth + 1;
            parent = root;
            return;
        }

        if (root->right != nullptr && root->right->val == x)
        {
            final_depth = temp_depth + 1;
            parent = root;
            return;
        }

        DFS(root->left, parent, x, final_depth, temp_depth + 1);
        DFS(root->right, parent, x, final_depth, temp_depth + 1);
    }

    //***********************
    bool isCousins(TreeNode *root, int x, int y)
    {

        TreeNode *xparent = nullptr;
        TreeNode *yparent = nullptr;
        int xdepth = 0;
        int ydepth = 0;

        DFS(root, xparent, x, xdepth, 0);
        DFS(root, yparent, y, ydepth, 0);

        return (xdepth == ydepth && xparent != yparent) ? true : false;
    }
};