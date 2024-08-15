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
    void DFS(TreeNode *Root, vector<string> &Paths, string path)
    {
        if (Root == NULL)
            return;

        path += to_string(Root->val);

        if (Root->left == NULL && Root->right == NULL)
        {
            Paths.push_back(path);
            path.pop_back();
        }
        else
        {
            path += "->";
        }

        DFS(Root->left, Paths, path);
        DFS(Root->right, Paths, path);
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {

        vector<string> Paths;
        DFS(root, Paths, "");

        return Paths;
    }
};