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
    void DFS(TreeNode *root, int target_sum, int &Count, long long int PathSum)
    {
        if (root == nullptr)
            return;

        PathSum = PathSum + root->val;

        if (PathSum == target_sum)
        {
            Count++;
        }

        DFS(root->left, target_sum, Count, PathSum);
        DFS(root->right, target_sum, Count, PathSum);
    }

    void Traverse_From_Each_Node(TreeNode *root, int target_sum, int &count)
    {
        if (root == nullptr)
            return;

        DFS(root, target_sum, count, 0);
        Traverse_From_Each_Node(root->left, target_sum, count);
        Traverse_From_Each_Node(root->right, target_sum, count);
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        int Count = 0;
        Traverse_From_Each_Node(root, targetSum, Count);

        return Count;
    }
};