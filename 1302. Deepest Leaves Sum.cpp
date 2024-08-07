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
    int BSF(TreeNode *Root)
    {
        vector<int> Sums;
        queue<TreeNode *> Nodes;
        int sum = 0;
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

                if (Temp->left != NULL)
                    Nodes.push(Temp->left);

                if (Temp->right != NULL)
                    Nodes.push(Temp->right);
            }
        }

        return Sums[Sums.size() - 1];
    }

    //****************************************
    int deepestLeavesSum(TreeNode *root)
    {

        return BSF(root);
    }
};