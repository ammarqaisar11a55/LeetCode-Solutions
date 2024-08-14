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
    void PreOrder(TreeNode *Root, int targetSum, vector<int> SinglePath, vector<vector<int>> &Ans)
    {
        if (Root == NULL)
        {
            return;
        }

        targetSum -= Root->val;
        SinglePath.push_back(Root->val);

        if (Root->left == NULL && Root->right == NULL && targetSum == 0)
        {
            Ans.push_back(SinglePath);
            SinglePath.pop_back();
        }

        PreOrder(Root->left, targetSum, SinglePath, Ans);
        PreOrder(Root->right, targetSum, SinglePath, Ans);
    }

    //*******************
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {

        vector<vector<int>> Ans;
        vector<int> SinglePath;
        PreOrder(root, targetSum, SinglePath, Ans);
        return Ans;
    }
};