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
    void DFS(TreeNode *root, vector<int> &Ans)
    {
        if (root == NULL)
        {
            return;
        }

        Ans.push_back(root->val);

        DFS(root->left, Ans);
        DFS(root->right, Ans);
    }

    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {

        vector<int> Ans;
        DFS(root1, Ans);
        DFS(root2, Ans);
        sort(Ans.begin(), Ans.end());
        return Ans;
    }
};