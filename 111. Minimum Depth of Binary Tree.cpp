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
    void DFS(TreeNode *root, int &ans, int temp)
    {
        if (root == nullptr)
            return;

        temp += 1;

        if (root->left == nullptr && root->right == nullptr)
        {
            ans = min(temp, ans);
        }

        DFS(root->left, ans, temp);
        DFS(root->right, ans, temp);
    }

    int minDepth(TreeNode *root)
    {

        if (root == nullptr)
            return 0;
        int ans = INT_MAX;
        DFS(root, ans, 0);
        return ans;
    }
};