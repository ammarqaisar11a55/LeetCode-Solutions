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
    int LevelOrderTraversal(TreeNode *Root)
    {
        queue<TreeNode *> Nodes;
        vector<int> Rows;
        int BottomMostLeft;
        Nodes.push(Root);
        Nodes.push(NULL);

        while (!Nodes.empty())
        {
            TreeNode *Temp = Nodes.front();
            Nodes.pop();

            if (Temp == NULL)
            {
                BottomMostLeft = Rows[0];
                Rows.clear();

                if (!Nodes.empty())
                    Nodes.push(NULL);
            }
            else
            {
                Rows.push_back(Temp->val);

                if (Temp->left)
                    Nodes.push(Temp->left);

                if (Temp->right)
                    Nodes.push(Temp->right);
            }
        }

        return BottomMostLeft;
    }

    /////////////////*******************
    int findBottomLeftValue(TreeNode *root)
    {
        return LevelOrderTraversal(root);
    }
};