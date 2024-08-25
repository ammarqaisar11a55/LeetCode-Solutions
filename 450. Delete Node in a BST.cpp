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
    int Minimumval(TreeNode *root)
    {
        TreeNode *temp = root;

        while (temp->left != nullptr)
        {
            temp = temp->left;
        }

        return temp->val;
    }
    //******************************************
    TreeNode *deleteNode(TreeNode *root, int key)
    {

        if (root == nullptr)
        {
            return root;
        }

        if (root->val == key)
        {
            // If This node has no child:
            if (root->left == nullptr && root->right == nullptr)
            {
                delete root;
                return nullptr;
            }

            // If This node has one child:
            // if it is right:

            if (root->left == nullptr && root->right != nullptr)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }

            // If This node has one child:
            // if it is left:

            if (root->left != nullptr && root->right == nullptr)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }

            // If child has two childs:
            if (root->left != nullptr && root->right != nullptr)
            {
                // Either Take minimum value from right or maximum value from left
                int mini = Minimumval(root->right);
                root->val = mini;
                root->right = deleteNode(root->right, mini);
                return root;
            }
        }

        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
    }
};