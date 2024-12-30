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
    void DFS_Calculate_Level_Sum(TreeNode *root, unordered_map<int, int> &Sums, int depth = 0)
    {
        if (root == nullptr)
        {
            return;
        }

        Sums[depth] += root->val;

        DFS_Calculate_Level_Sum(root->left, Sums, depth + 1);
        DFS_Calculate_Level_Sum(root->right, Sums, depth + 1);
    }

    void DFS_Replace(TreeNode *&root, int Sibling_Val, unordered_map<int, int> &Sums, int depth)
    {
        if (root == nullptr)
            return;

        cout << endl;
        cout << endl;
        cout << endl;

        int left_Sib = root->left == nullptr ? 0 : root->left->val;
        int right_Sib = root->right == nullptr ? 0 : root->right->val;

        int Current_Level_Sum = Sums[depth] - root->val - Sibling_Val;
        root->val = Current_Level_Sum;

        DFS_Replace(root->left, right_Sib, Sums, depth + 1);
        DFS_Replace(root->right, left_Sib, Sums, depth + 1);
    }

    TreeNode *replaceValueInTree(TreeNode *root)
    {

        unordered_map<int, int> Level_Sums;
        DFS_Calculate_Level_Sum(root, Level_Sums);

        DFS_Replace(root, 0, Level_Sums, 0);

        return root;
    }
};