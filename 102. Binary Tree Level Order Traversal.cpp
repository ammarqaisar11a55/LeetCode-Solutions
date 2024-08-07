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
    void BFS(TreeNode *Root, vector<vector<int>> &Ans)
    {
        queue<TreeNode *> Nodes;
        vector<int> LevelData;
        Nodes.push(Root);
        Nodes.push(NULL);

        while (!Nodes.empty())
        {
            TreeNode *Temp = Nodes.front();
            Nodes.pop();

            if (Temp == NULL)
            {
                Ans.push_back(LevelData);
                LevelData.clear();

                if (!Nodes.empty())
                    Nodes.push(NULL);
            }
            else
            {
                LevelData.push_back(Temp->val);

                if (Temp->left != NULL)
                    Nodes.push(Temp->left);

                if (Temp->right != NULL)
                    Nodes.push(Temp->right);
            }
        }
    }

    //********************************************
    vector<vector<int>> levelOrder(TreeNode *root)
    {

        if (root == NULL)
            return {};

        vector<vector<int>> Ans;
        BFS(root, Ans);
        return Ans;
    }
};