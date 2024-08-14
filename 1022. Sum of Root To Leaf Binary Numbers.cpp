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
    int Decimal_Conversion(vector<int> BinaryNumber)
    {
        int ans = 0;
        int j = 0;

        for (int i = BinaryNumber.size() - 1; i >= 0; i--)
        {
            ans += BinaryNumber[i] * pow(2, j++);
        }

        return ans;
    }

    void DFS(TreeNode *Root, vector<int> Path, vector<vector<int>> &BinaryNumbers)
    {
        if (Root == NULL)
            return;

        Path.push_back(Root->val);

        if (Root->left == NULL && Root->right == NULL)
        {
            BinaryNumbers.push_back(Path);
            Path.pop_back();
        }

        DFS(Root->left, Path, BinaryNumbers);
        DFS(Root->right, Path, BinaryNumbers);
    }

    //*********************************
    int sumRootToLeaf(TreeNode *root)
    {

        vector<int> Path;
        vector<vector<int>> BinaryNumbers;
        DFS(root, Path, BinaryNumbers);
        int sum = 0;

        for (int i = 0; i < BinaryNumbers.size(); i++)
        {
            sum += Decimal_Conversion(BinaryNumbers[i]);
        }

        return sum;
    }
};