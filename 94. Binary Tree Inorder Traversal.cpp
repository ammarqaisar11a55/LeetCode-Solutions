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
    void InOrderTraversalIteratively(TreeNode *Root, vector<int> &Ans)
    {
        stack<TreeNode *> Nodes;
        TreeNode *Current = Root;

        while (Current != NULL || !Nodes.empty())
        {
            // Visit The Left Most Node:
            while (Current != NULL)
            {
                Nodes.push(Current);
                Current = Current->left;
            }

            Current = Nodes.top();

            Ans.push_back(Current->val);
            Nodes.pop();

            // Visit the Right Subtree:

            Current = Current->right;
        }
    }

    //****************
    vector<int> inorderTraversal(TreeNode *root)
    {

        if (root == NULL)
            return {};

        vector<int> Ans;
        InOrderTraversalIteratively(root, Ans);
        return Ans;
    }
};