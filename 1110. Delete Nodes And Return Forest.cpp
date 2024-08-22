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
    TreeNode *DFS(TreeNode *root, vector<TreeNode *> &Ans, unordered_set<int> &St)
    {
        if (root == NULL)
        {
            return NULL;
        }

        root->left = DFS(root->left, Ans, St);
        root->right = DFS(root->right, Ans, St);

        if (St.find(root->val) != St.end())
        {
            if (root->left)
                Ans.push_back(root->left);

            if (root->right)
                Ans.push_back(root->right);

            return NULL;
        }
        else
            return root;
    }

    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {

        vector<TreeNode *> Ans;
        unordered_set<int> St;

        for (auto x : to_delete)
        {
            St.insert(x);
        }

        DFS(root, Ans, St);

        if (St.find(root->val) == St.end())
        {
            Ans.push_back(root);
        }

        return Ans;
    }
};