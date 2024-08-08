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
    void LevelOrderTraversal(TreeNode *Root, vector<int> &Ans)
    {
        vector<int> Rows;
        queue<TreeNode *> Nodes;
        Nodes.push(Root);
        Nodes.push(NULL);

        while (!Nodes.empty())
        {
            TreeNode *Temp = Nodes.front();
            Nodes.pop();

            if (Temp == NULL)
            {
                Ans.push_back(Rows[Rows.size() - 1]);
                Rows.clear();

                if (!Nodes.empty())
                    Nodes.push(NULL);
            }
            else
            {
                Rows.push_back(Temp->val);

                if (Temp->left != NULL)
                    Nodes.push(Temp->left);

                if (Temp->right != NULL)
                    Nodes.push(Temp->right);
            }
        }
    }

    //***********************************************
    vector<int> rightSideView(TreeNode *root)
    {

        if (root == NULL)
            return {};

        vector<int> Ans;
        LevelOrderTraversal(root, Ans);
        return Ans;
    }
};