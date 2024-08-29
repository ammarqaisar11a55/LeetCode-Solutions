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
    bool isCompleteTree(TreeNode *root)
    {

        queue<TreeNode *> Q;

        Q.push(root);
        bool seen_null = false;

        while (!Q.empty())
        {
            TreeNode *temp = Q.front();
            Q.pop();

            if (temp == nullptr)
            {
                seen_null = true;
            }
            else
            {
                if (seen_null == true)
                {
                    return false;
                }

                Q.push(temp->left);
                Q.push(temp->right);
            }
        }

        return true;
    }
};

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
    void DFS(TreeNode *root, int index, int total, int &ans)
    {
        if (root == nullptr)
            return;

        if (index > total)
        {
            ans = 0;
            return;
        }

        DFS(root->left, 2 * index, total, ans);
        DFS(root->right, 2 * index + 1, total, ans);
    }

    int count(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        return 1 + count(root->left) + count(root->right);
    }

    bool isCompleteTree(TreeNode *root)
    {

        int total = count(root);
        int ans = 1;

        DFS(root, 1, total, ans);

        return ans == 1 ? true : false;
    }
};