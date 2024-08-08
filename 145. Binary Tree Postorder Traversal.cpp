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
    void PostOrderTraversalIteratively(TreeNode *Root, vector<int> &Ans)
    {
        if (Root == NULL)
            return;

        stack<TreeNode *> N1, N2;

        N1.push(Root);

        while (!N1.empty())
        {
            TreeNode *Temp = N1.top();
            N1.pop();
            N2.push(Temp);

            if (Temp->left != NULL)
                N1.push(Temp->left);

            if (Temp->right != NULL)
                N1.push(Temp->right);
        }

        while (!N2.empty())
        {
            Ans.push_back(N2.top()->val);
            N2.pop();
        }
    }

    //*******************************

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> Ans;
        PostOrderTraversalIteratively(root, Ans);
        return Ans;
    }
};