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
    void BFS(TreeNode *Root, vector<double> &Ans)
    {
        long long sum = 0;
        int count = 0;

        queue<TreeNode *> Nodes;
        Nodes.push(Root);
        Nodes.push(NULL);

        while (!Nodes.empty())
        {
            TreeNode *Temp = Nodes.front();
            Nodes.pop();

            if (Temp == NULL)
            {
                double avg = (double)sum / count;
                Ans.push_back(avg);
                sum = count = 0;

                if (!Nodes.empty())
                    Nodes.push(NULL);
            }
            else
            {
                sum += Temp->val;
                count++;

                if (Temp->left != NULL)
                    Nodes.push(Temp->left);

                if (Temp->right != NULL)
                    Nodes.push(Temp->right);
            }
        }
    }

    //***********************************************
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> Ans;
        BFS(root, Ans);
        return Ans;
    }
};