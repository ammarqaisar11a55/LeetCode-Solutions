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
    void DFS(TreeNode *root, int &MaxLength, int Current_length, char Direction)
    {
        if (root == nullptr)
        {
            MaxLength = max(MaxLength, Current_length - 1);
            return;
        }

        if (Direction == 'R')
        {
            DFS(root->left, MaxLength, Current_length + 1, 'L');
            DFS(root->right, MaxLength, 1, 'R');
        }
        else if (Direction == 'L')
        {
            DFS(root->right, MaxLength, Current_length + 1, 'R');
            DFS(root->left, MaxLength, 1, 'L');
        }
    }

    int longestZigZag(TreeNode *root)
    {

        int Res = 0;
        DFS(root, Res, 0, 'R');
        DFS(root, Res, 0, 'L');
        return Res;
    }
};