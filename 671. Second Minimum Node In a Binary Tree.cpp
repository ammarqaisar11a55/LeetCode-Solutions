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
    void DFS(TreeNode *Root, set<int> &S)
    {
        if (Root == NULL)
            return;

        S.insert(Root->val);

        DFS(Root->left, S);
        DFS(Root->right, S);
    }

    int findSecondMinimumValue(TreeNode *root)
    {

        set<int> S;

        DFS(root, S);

        if (S.size() == 1)
            return -1;

        auto it = S.begin();
        it++;

        return *it;
    }
};