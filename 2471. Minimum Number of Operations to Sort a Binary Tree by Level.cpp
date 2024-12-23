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
    int getMinSwaps(vector<int> &Original)
    {
        vector<int> Sorted = Original;
        sort(Sorted.begin(), Sorted.end());

        int countSwaps = 0;

        unordered_map<int, int> mp;

        for (int i = 0; i < Original.size(); i++)
        {
            mp[Original[i]] = i;
        }

        for (int i = 0; i < Sorted.size(); i++)
        {
            //             if(mp[Sorted[i]]!=i)
            //             {
            //                 int Current_Sorted_Element = Sorted[i];
            //                 int its_pos = mp[Current_Sorted_Element];

            //                 int Origianl_vector_Element_at_current_ps = Original[i];
            //                 int Current_extracted_element_pos = mp[Origianl_vector_Element_at_current_ps];

            //                 mp[Current_Sorted_Element] = Current_extracted_element_pos;
            //                 mp[Origianl_vector_Element_at_current_ps] = its_pos;

            //                 countSwaps++;
            //             }

            if (Sorted[i] != Original[i])
            {

                int Current_Original_Pos_in_mp = mp[Original[i]];
                int Current_Sorted_Pos_in_mp = mp[Sorted[i]];

                swap(Original[Current_Original_Pos_in_mp], Original[Current_Sorted_Pos_in_mp]);

                mp[Original[Current_Original_Pos_in_mp]] = Current_Original_Pos_in_mp;
                mp[Original[Current_Sorted_Pos_in_mp]] = Current_Sorted_Pos_in_mp;

                countSwaps++;
            }
        }

        return countSwaps;
    }

    void BFS(TreeNode *root, int &minswaps)
    {

        queue<TreeNode *> nodes;
        vector<int> Level_Nodes;
        nodes.push(root);
        nodes.push(nullptr);

        while (!nodes.empty())
        {
            TreeNode *frontNode = nodes.front();
            nodes.pop();

            if (frontNode == nullptr)
            {
                if (Level_Nodes.empty() == false)
                {

                    if (Level_Nodes.size() > 1)
                    {
                        minswaps += getMinSwaps(Level_Nodes);
                    }

                    Level_Nodes.clear();
                }

                if (!nodes.empty())
                {
                    nodes.push(nullptr);
                }
            }
            else
            {
                Level_Nodes.push_back(frontNode->val);

                if (frontNode->left)
                    nodes.push(frontNode->left);

                if (frontNode->right)
                    nodes.push(frontNode->right);
            }
        }
    }

    int minimumOperations(TreeNode *root)
    {
        int res = 0;
        BFS(root, res);
        return res;
    }
};