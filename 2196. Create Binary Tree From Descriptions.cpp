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
    void Creation(TreeNode *&Root, int Val, unordered_map<int, int> &Left_Childs, unordered_map<int, int> &Right_Childs)
    {
        if (Root == nullptr)
        {
            Root = new TreeNode(Val);
        }

        int Left_Child = -1;
        int Right_Child = -1;

        if (Left_Childs.find(Root->val) != Left_Childs.end())
        {
            Creation(Root->left, Left_Childs[Root->val], Left_Childs, Right_Childs);
        }

        if (Right_Childs.find(Root->val) != Right_Childs.end())
        {
            Creation(Root->right, Right_Childs[Root->val], Left_Childs, Right_Childs);
        }
    }

    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        int Root_Node_Val = -1;
        unordered_map<int, bool> Childs;

        for (vector<int> Single_Node : descriptions)
        {
            Childs[Single_Node[1]] = Single_Node[2];
        }

        for (vector<int> Single_Node : descriptions)
        {
            if (Childs.find(Single_Node[0]) == Childs.end())
            {
                Root_Node_Val = Single_Node[0];
                break;
            }
        }

        TreeNode *Root_Node = new TreeNode(Root_Node_Val);

        unordered_map<int, int> Left_Childs;
        unordered_map<int, int> Right_Childs;

        for (int i = 0; i < descriptions.size(); i++)
        {
            if (descriptions[i][2] == 1)
            {
                Left_Childs[descriptions[i][0]] = descriptions[i][1];
            }
            else
            {
                Right_Childs[descriptions[i][0]] = descriptions[i][1];
            }
        }

        Creation(Root_Node, Root_Node_Val, Left_Childs, Right_Childs);

        return Root_Node;
    }
};