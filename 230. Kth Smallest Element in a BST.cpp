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
    void Inorder(TreeNode *root, vector<int> &Nodes)
    {
        if (root == NULL)
            return;

        Inorder(root->left, Nodes);
        Nodes.push_back(root->val);
        Inorder(root->right, Nodes);
    }
    //*************
    int kthSmallest(TreeNode *root, int k)
    {

        vector<int> Nodes;
        Inorder(root, Nodes);

        sort(Nodes.begin(), Nodes.end());

        return Nodes[k - 1];
    }
};