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
    void build(TreeNode *&root, int data)
    {

        if (root == nullptr)
        {
            root = new TreeNode(data);
            return;
        }

        if (root->val > data)
        {
            build(root->left, data);
        }
        else
            build(root->right, data);
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {

        TreeNode *root = nullptr;

        for (auto x : preorder)
        {
            build(root, x);
        }

        return root;
    }
};