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
    void flatten(TreeNode *root)
    {

        if (root == nullptr)
            return;

        TreeNode *Current = root;

        while (Current != nullptr)
        {
            if (Current->left != nullptr)
            {
                TreeNode *Temp = Current->left;

                while (Temp->right != NULL)
                    Temp = Temp->right;

                Temp->right = Current->right;
                Current->right = Current->left;
                Current->left = nullptr;
            }
            Current = Current->right;
        }
    }
};