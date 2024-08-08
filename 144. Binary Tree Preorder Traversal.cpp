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
    void PreOrderTraversalIteratively(TreeNode *Root, vector<int> &Ans)
    {
        if (Root == NULL)
            return;

        stack<TreeNode *> Nodes;
        Nodes.push(Root);

        while (!Nodes.empty())
        {
            TreeNode *Temp = Nodes.top();
            Nodes.pop();

            Ans.push_back(Temp->val);

            if (Temp->right != NULL)
                Nodes.push(Temp->right);

            if (Temp->left != NULL)
                Nodes.push(Temp->left);
        }
    }

    //*****************
    vector<int> preorderTraversal(TreeNode *root)
    {

        vector<int> Ans;
        PreOrderTraversalIteratively(root, Ans);
        return Ans;
    }
};