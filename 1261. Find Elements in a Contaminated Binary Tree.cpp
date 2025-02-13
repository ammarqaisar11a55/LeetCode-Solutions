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
class FindElements
{
public:
    unordered_set<int> st;

    void DFS(TreeNode *root, int parent)
    {
        if (root == nullptr)
        {
            return;
        }

        if (parent == -1)
        {
            root->val = 0;
        }
        else
        {
            root->val = parent;
        }

        st.insert(root->val);

        DFS(root->left, root->val * 2 + 1);
        DFS(root->right, root->val * 2 + 2);
    }

    FindElements(TreeNode *root)
    {
        DFS(root, -1);
    }

    bool find(int target)
    {
        return st.find(target) != st.end() ? true : false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */