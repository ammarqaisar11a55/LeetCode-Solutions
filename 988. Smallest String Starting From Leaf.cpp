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
    void DFS(TreeNode *root, string current, string &SmallestAns)
    {
        if (root == NULL)
            return;

        current = char(root->val + 'a') + current;

        if (root->left == NULL && root->right == NULL)
        {
            if (SmallestAns == "" || current < SmallestAns)
                SmallestAns = current;

            current.pop_back();
        }

        DFS(root->left, current, SmallestAns);
        DFS(root->right, current, SmallestAns);
    }

    string smallestFromLeaf(TreeNode *root)
    {

        string ans;

        DFS(root, "", ans);
        return ans;
    }
};