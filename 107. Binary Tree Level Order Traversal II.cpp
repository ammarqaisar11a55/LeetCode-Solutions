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
    void ReverseLevelOrderTraversal(TreeNode *Root, vector<vector<int>> &Ans)
    {
        queue<TreeNode *> Nodes;
        stack<TreeNode *> ReverseOrder;

        Nodes.push(Root);
        Nodes.push(NULL);

        while (!Nodes.empty())
        {
            TreeNode *Temp = Nodes.front();
            Nodes.pop();

            if (Temp == NULL)
            {
                ReverseOrder.push(NULL);

                if (!Nodes.empty())
                    Nodes.push(NULL);
            }
            else
            {
                ReverseOrder.push(Temp);

                if (Temp->right != NULL)
                    Nodes.push(Temp->right);

                if (Temp->left != NULL)
                    Nodes.push(Temp->left);
            }
        }

        vector<int> Level;

        while (!ReverseOrder.empty())
        {

            if (ReverseOrder.top() == NULL)
            {
                if (!Level.empty())
                    Ans.push_back(Level);
                Level.clear();
            }
            else
            {
                Level.push_back(ReverseOrder.top()->val);
            }

            ReverseOrder.pop();
        }

        if (!Level.empty())
            Ans.push_back(Level);
    }

    //******************************
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {

        if (root == NULL)
            return {};

        vector<vector<int>> ANS;
        ReverseLevelOrderTraversal(root, ANS);
        return ANS;
    }
};