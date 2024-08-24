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
    void DFS(TreeNode *root, vector<int> &Inorder)
    {
        if (root == nullptr)
            return;

        DFS(root->left, Inorder);
        Inorder.push_back(root->val);
        DFS(root->right, Inorder);
    }

    TreeNode *build(vector<int> &Inorder, int start, int end)
    {
        if (start > end)
            return nullptr;

        int mid = start + (end - start) / 2;

        TreeNode *root = new TreeNode(Inorder[mid]);

        root->left = build(Inorder, start, mid - 1);
        root->right = build(Inorder, mid + 1, end);

        return root;
    }

    TreeNode *balanceBST(TreeNode *root)
    {

        vector<int> Inorder;
        DFS(root, Inorder);

        return build(Inorder, 0, Inorder.size() - 1);
    }
};