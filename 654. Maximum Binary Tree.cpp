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
    int Maxi(int left, int right, vector<int> nums)
    {
        int Max_Index = -1;
        int Max_Element = INT_MIN;

        for (int i = left; i < right; i++)
        {
            if (Max_Element < nums[i])
            {
                Max_Element = nums[i];
                Max_Index = i;
            }
        }

        return Max_Index;
    }

    TreeNode *DFS(vector<int> Nums, int left, int right)
    {
        if (left == right)
        {
            return nullptr;
        }

        int MaxElementIndex = Maxi(left, right, Nums);

        TreeNode *Root = new TreeNode(Nums[MaxElementIndex]);
        Root->left = DFS(Nums, left, MaxElementIndex);
        Root->right = DFS(Nums, MaxElementIndex + 1, right);

        return Root;
    }

    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {

        int left = 0;
        int right = nums.size();

        return DFS(nums, left, right);
    }
};