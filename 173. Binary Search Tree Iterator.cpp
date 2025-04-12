/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<int> values;
    int index = 0;

    void DFS(TreeNode* root) {
        if (root == nullptr)
            return;

        DFS(root->left);
        values.push_back(root->val);
        DFS(root->right);
    }

    BSTIterator(TreeNode* root) { DFS(root); }

    int next() {
        int ans = values[index++];
        return ans;
    }

    bool hasNext() { return index < values.size() ? true : false; }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
