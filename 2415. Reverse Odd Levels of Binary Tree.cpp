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
    void GetValuesBFT(TreeNode *Root, vector<vector<int>> &Grid)
    {
        vector<int> LevelNodes;

        queue<TreeNode *> Nodes;

        Nodes.push(Root);
        Nodes.push(NULL);
        int row = 0;

        while (!Nodes.empty())
        {
            TreeNode *Temp = Nodes.front();
            Nodes.pop();

            if (Temp == NULL)
            {
                if (row % 2 != 0)
                    reverse(LevelNodes.begin(), LevelNodes.end());

                Grid.push_back(LevelNodes);
                LevelNodes.clear();
                row++;

                if (!Nodes.empty())
                    Nodes.push(NULL);
            }
            else
            {
                LevelNodes.push_back(Temp->val);

                if (Temp->left)
                    Nodes.push(Temp->left);
                if (Temp->right)
                    Nodes.push(Temp->right);
            }
        }
    }

    void ReplaceValuesBFT(TreeNode *Root, vector<vector<int>> &Grid)
    {
        vector<int> LevelNodes;

        queue<TreeNode *> Nodes;

        Nodes.push(Root);
        Nodes.push(NULL);
        int i = 0, j = 0;

        while (!Nodes.empty())
        {
            TreeNode *Temp = Nodes.front();
            Nodes.pop();

            if (Temp == NULL)
            {
                i++;
                j = 0;

                if (!Nodes.empty())
                    Nodes.push(NULL);
            }
            else
            {
                Temp->val = Grid[i][j++];

                if (Temp->left)
                    Nodes.push(Temp->left);
                if (Temp->right)
                    Nodes.push(Temp->right);
            }
        }
    }

    //********************************
    TreeNode *reverseOddLevels(TreeNode *root)
    {

        vector<vector<int>> Matrix;
        GetValuesBFT(root, Matrix);
        ReplaceValuesBFT(root, Matrix);

        return root;
    }
};