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
    void ConstructTreeFromInorderAndPostorder(TreeNode *&Root, vector<int> &postorder, vector<int> &inorder, int &index, int inorderstart, int inorderend, unordered_map<int, int> &Positions)
    {
        if (index < 0 || inorderstart > inorderend)
            return;

        int element = postorder[index--];
        Root = new TreeNode(element);
        int position = Positions[element];

        ConstructTreeFromInorderAndPostorder(Root->right, postorder, inorder, index, position + 1, inorderend, Positions);
        ConstructTreeFromInorderAndPostorder(Root->left, postorder, inorder, index, inorderstart, position - 1, Positions);
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {

        TreeNode *Root = NULL;

        unordered_map<int, int> Position;

        for (int i = 0; i < inorder.size(); i++)
            Position[inorder[i]] = i;

        int index = inorder.size() - 1;
        ConstructTreeFromInorderAndPostorder(Root, postorder, inorder, index, 0, inorder.size() - 1, Position);
        return Root;
    }
};