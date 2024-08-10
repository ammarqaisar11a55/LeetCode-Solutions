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
    void BFT(TreeNode *Root, vector<vector<int>> &Ans)
    {
        queue<TreeNode *> Nodes;
        Nodes.push(Root);
        Nodes.push(NULL);
        int RowNo = 1;
        vector<int> RowElement;

        while (!Nodes.empty())
        {
            TreeNode *Temp = Nodes.front();
            Nodes.pop();

            if (Temp == NULL)
            {
                if (RowNo % 2 == 0)
                    reverse(begin(RowElement), end(RowElement));

                Ans.push_back(RowElement);
                RowNo++;
                RowElement.clear();

                if (!Nodes.empty())
                    Nodes.push(NULL);
            }
            else
            {
                RowElement.push_back(Temp->val);

                if (Temp->left)
                    Nodes.push(Temp->left);

                if (Temp->right)
                    Nodes.push(Temp->right);
            }
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {

        if (root == NULL)
            return {};

        vector<vector<int>> Ans;
        BFT(root, Ans);
        return Ans;
    }
};