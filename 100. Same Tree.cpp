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
    void PreOrder(TreeNode *Root, vector<int> &Nodes)
    {
        if (Root == NULL)
        {
            Nodes.push_back(pow(-10, 5));
            return;
        }

        Nodes.push_back(Root->val);
        PreOrder(Root->left, Nodes);
        PreOrder(Root->right, Nodes);
    }
    //****************
    bool isSameTree(TreeNode *p, TreeNode *q)
    {

        vector<int> PNodes;
        vector<int> QNodes;
        PreOrder(p, PNodes);
        PreOrder(q, QNodes);

        return PNodes == QNodes ? true : false;
    }
};