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
    bool isCompleteTree(TreeNode *root)
    {

        queue<TreeNode *> Q;

        Q.push(root);
        bool seen_null = false;

        while (!Q.empty())
        {
            TreeNode *temp = Q.front();
            Q.pop();

            if (temp == nullptr)
            {
                seen_null = true;
            }
            else
            {
                if (seen_null == true)
                {
                    return false;
                }

                Q.push(temp->left);
                Q.push(temp->right);
            }
        }

        return true;
    }
};