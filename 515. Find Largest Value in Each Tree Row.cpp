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
    void LevelOrderTraversal(TreeNode *Root, vector<int> &ANS)
    {
        vector<int> RS;

        queue<TreeNode *> Nodes;

        Nodes.push(Root);
        Nodes.push(NULL);

        while (!Nodes.empty())
        {
            TreeNode *Temp = Nodes.front();
            Nodes.pop();

            if (Temp == NULL)
            {
                ANS.push_back(*max_element(RS.begin(), RS.end()));
                RS.clear();

                if (!Nodes.empty())
                    Nodes.push(NULL);
            }
            else
            {
                RS.push_back(Temp->val);

                if (Temp->left != NULL)
                {
                    Nodes.push(Temp->left);
                }

                if (Temp->right != NULL)
                {
                    Nodes.push(Temp->right);
                }
            }
        }
    }

    ///************************************************
    vector<int> largestValues(TreeNode *root)
    {

        if (root == NULL)
            return {};

        vector<int> ANS;
        LevelOrderTraversal(root, ANS);
        return ANS;
    }
};