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
    void DFS(TreeNode *Root, int low, int high, vector<int> &Nodes)
    {
        if (Root == NULL)
            return;

        if (Root->val >= low && Root->val <= high)
        {
            Nodes.push_back(Root->val);
        }

        DFS(Root->left, low, high, Nodes);
        DFS(Root->right, low, high, Nodes);
    }

    int rangeSumBST(TreeNode *root, int low, int high)
    {

        if (root == NULL)
            return {};

        vector<int> Nodes;
        DFS(root, low, high, Nodes);

        return accumulate(Nodes.begin(), Nodes.end(), 0, plus<int>());
    }
};