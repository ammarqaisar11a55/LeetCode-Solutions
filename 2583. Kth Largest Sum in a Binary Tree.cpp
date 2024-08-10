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
    void BFT(TreeNode *root, vector<unsigned long long int> &Sums)
    {
        queue<TreeNode *> Nodes;
        Nodes.push(root);
        Nodes.push(NULL);
        unsigned long long int sum = 0;

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

    //***************
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        vector<unsigned long long int> Sums;

        BFT(root, Sums);

        if (Sums.size() < k)
            return -1;

        sort(rbegin(Sums), rend(Sums));

        return Sums[k - 1];
    }
};