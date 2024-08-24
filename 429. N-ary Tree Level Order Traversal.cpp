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
    void BFS(Node *root, vector<vector<int>> &Ans)
    {
        if (root == nullptr)
            return;

        queue<Node *> Q;
        Q.push(root);

        while (!Q.empty())
        {
            int n = Q.size();
            vector<int> level;
            for (int i = 0; i < n; i++)
            {
                Node *current = Q.front();
                Q.pop();

                level.push_back(current->val);

                for (auto child : current->children)
                    Q.push(child);
            }
            Ans.push_back(level);
            // level.clear();
        }
    }

    vector<vector<int>> levelOrder(Node *root)
    {

        vector<vector<int>> Ans;
        BFS(root, Ans);
        return Ans;
    }
};