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
    void Build_Binary_Search_Tree(TreeNode *&root, int data)
    {
        if (root == nullptr)
        {
            root = new TreeNode(data);
            return;
        }

        Build_Binary_Search_Tree(root->right, data);

        // Time Complexity : O(Log N)
        // Space Complexity : O(Log N)
    }

    void DFS(TreeNode *root, vector<int> &Nodes)
    {
        if (root == nullptr)
            return;

        DFS(root->left, Nodes);
        Nodes.push_back(root->val);
        DFS(root->right, Nodes);
    }

    TreeNode *increasingBST(TreeNode *root)
    {

        vector<int> Nodes;
        DFS(root, Nodes);

        TreeNode *ans = nullptr;

        for (int i = 0; i < Nodes.size(); i++)
        {
            Build_Binary_Search_Tree(ans, Nodes[i]);
        }

        return ans;
    }
};