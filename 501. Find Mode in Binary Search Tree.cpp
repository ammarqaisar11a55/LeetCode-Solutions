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
    void DFS(TreeNode *Root, unordered_map<int, int> &Freq)
    {
        if (Root == NULL)
            return;

        Freq[Root->val]++;

        DFS(Root->left, Freq);
        DFS(Root->right, Freq);
    }

    vector<int> findMode(TreeNode *root)
    {

        unordered_map<int, int> Freq;
        DFS(root, Freq);

        int max_Freq = 0;

        for (auto x : Freq)
            max_Freq = max(max_Freq, x.second);

        vector<int> Ans;

        for (auto x : Freq)
        {
            if (x.second == max_Freq)
                Ans.push_back(x.first);
        }

        return Ans;
    }
};