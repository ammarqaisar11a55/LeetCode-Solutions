/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNointde *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int DFS(TreeNode *root, int &res)
    {
        if (root == nullptr)
            return 0;

        int left = DFS(root->left, res);
        int right = DFS(root->right, res);

        res += abs(left - right);

        return left + right + root->val;
    }

    int findTilt(TreeNode *root)
    {

        int res = 0;
        DFS(root, res);

        return res;
    }
};