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
    void PreOrder(TreeNode *root, vector<int> &leafs)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
            leafs.push_back(root->val);

        PreOrder(root->left, leafs);
        PreOrder(root->right, leafs);
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {

        vector<int> Leafs1;
        vector<int> Leafs2;

        PreOrder(root1, Leafs1);
        PreOrder(root2, Leafs2);

        return Leafs1 == Leafs2 ? true : false;
    }
};