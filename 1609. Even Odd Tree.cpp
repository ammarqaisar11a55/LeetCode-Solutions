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
    void BFS(TreeNode *Root, bool &ans)
    {
        int level = 0;
        int previous = 0;

        if (Root->val % 2 == 0)
        {
            ans = false;
            return;
        }

        queue<TreeNode *> Nodes;
        Nodes.push(Root);
        Nodes.push(NULL);

        while (!Nodes.empty())
        {
            TreeNode *Temp = Nodes.front();
            Nodes.pop();

            if (Temp == NULL)
            {
                level++;
                previous = 0;

                if (ans == false)
                    return;

                if (!Nodes.empty())
                    Nodes.push(NULL);
            }
            else
            {

                if (level >= 1 && level % 2 == 0)
                {
                    if (Temp->val % 2 == 0)
                    {
                        ans = false;
                        return;
                    }

                    if (previous == 0)
                    {
                        previous = Temp->val;
                    }
                    else if (previous != 0)
                    {
                        if (previous > Temp->val || previous == Temp->val)
                        {
                            ans = false;
                            return;
                        }
                        else
                        {
                            previous = Temp->val;
                        }
                    }
                }
                else if (level >= 1 && level % 2 != 0)
                {
                    if (Temp->val % 2 != 0)
                    {
                        ans = false;
                        return;
                    }

                    if (previous == 0)
                    {
                        previous = Temp->val;
                    }
                    else if (previous != 0)
                    {
                        if (previous < Temp->val || previous == Temp->val)
                        {
                            ans = false;
                            return;
                        }
                        else
                        {
                            previous = Temp->val;
                        }
                    }
                }

                if (Temp->left != NULL)
                    Nodes.push(Temp->left);

                if (Temp->right != NULL)
                    Nodes.push(Temp->right);
            }
        }
    }

    //***********************************
    bool isEvenOddTree(TreeNode *root)
    {
        bool ans = true;
        BFS(root, ans);
        return ans;
    }
};