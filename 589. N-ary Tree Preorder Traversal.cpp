/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    void DFS(Node *root, vector<int> &Ans)
    {
        if (root == nullptr)
            return;

        Ans.push_back(root->val);

        for (auto child : root->children)
        {
            DFS(child, Ans);
        }
    }

    vector<int> preorder(Node *root)
    {
        vector<int> ans;
        DFS(root, ans);
        return ans;
    }
};