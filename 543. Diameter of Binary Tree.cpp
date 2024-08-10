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
    pair<int, int> diameter(TreeNode *Root)
    {
        if (Root == NULL)
        {
            return {0, 0};
        }

        pair<int, int> Left = diameter(Root->left);
        pair<int, int> Right = diameter(Root->right);

        int diameterofleft = Left.first;
        int diameterofRight = Right.first;
        int height = Left.second + Right.second;

        pair<int, int> Ans;
        Ans.first = max(diameterofRight, max(diameterofleft, height));
        Ans.second = max(Left.second, Right.second) + 1;

        return Ans;
    }

    //****************
    int diameterOfBinaryTree(TreeNode *root)
    {

        return diameter(root).first;
    }
};