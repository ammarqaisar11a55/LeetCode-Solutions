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
    void DFS(TreeNode *root, int k, int &ans, unordered_set<int> &S)
    {
        if (root == nullptr)
            return;

        int diff = k - root->val;

        if (S.find(diff) != S.end())
        {
            ans = 1;
            return;
        }
        else
        {
            S.insert(root->val);
        }

        DFS(root->left, k, ans, S);
        DFS(root->right, k, ans, S);
    }

    bool findTarget(TreeNode *root, int k)
    {

        int ans = 0;
        unordered_set<int> S;
        DFS(root, k, ans, S);

        return ans == 0 ? false : true;
    }
};