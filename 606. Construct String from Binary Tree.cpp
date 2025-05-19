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
    void DFS(TreeNode*& root, string& res) {
        if (root == NULL)
            return;

        res += to_string(root->val);

        if (root->left != NULL) {
            res += "(";
            DFS(root->left, res);
            res += ")";
        }

        if (root->right != NULL) {
            if (root->left == NULL && root->right != NULL) {
                res += "()";
                res += "(";
                DFS(root->right, res);
                res += ")";
            } else if (root->right != NULL) {
                res += "(";
                DFS(root->right, res);
                res += ")";
            }
        }
    }

    string tree2str(TreeNode* root) {
        string res;
        DFS(root, res);
        return res;
    }
};
