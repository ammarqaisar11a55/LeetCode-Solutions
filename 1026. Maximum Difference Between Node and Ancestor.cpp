/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void DFS(TreeNode* root, int mini, int maxi, int& res) {
        if (root == nullptr) {
            res = max(res, maxi - mini);
            return;
        }

        mini = min(mini, root->val);
        maxi = max(maxi, root->val);
        res = max(res, maxi - mini);

        DFS(root->left, mini, maxi, res);
        DFS(root->right, mini, maxi, res);
    }

    int maxAncestorDiff(TreeNode* root) {

        int res = 0;

        DFS(root, root->val, root->val, res);

        return res;
    }
};
