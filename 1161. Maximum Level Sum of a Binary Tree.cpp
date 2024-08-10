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
    void BFT(TreeNode *Root, vector<int> &Sums)
    {
        int sum = 0;
        queue<TreeNode *> Nodes;
        Nodes.push(Root);
        Nodes.push(NULL);

        while (!Nodes.empty())
        {
            TreeNode *Temp = Nodes.front();
            Nodes.pop();

            if (Temp == NULL)
            {
                Sums.push_back(sum);
                sum = 0;

                if (!Nodes.empty())
                    Nodes.push(NULL);
            }
            else
            {
                sum += Temp->val;

                if (Temp->left)
                    Nodes.push(Temp->left);

                if (Temp->right)
                    Nodes.push(Temp->right);
            }
        }
    }

    //**************
    int maxLevelSum(TreeNode *root)
    {

        vector<int> Sum;
        BFT(root, Sum);

        int maximum = INT_MIN;
        int level = -1;

        for (int i = 0; i < Sum.size(); i++)
        {
            if (Sum[i] > maximum)
            {
                maximum = Sum[i];
                level = i + 1;
            }
        }
        return level;
    }
};