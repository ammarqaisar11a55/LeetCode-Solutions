class Solution
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {

        unordered_set<int> Nodes_With_No_Incomes;

        for (int i = 0; i < n; i++)
            Nodes_With_No_Incomes.insert(i);

        for (vector<int> EDGE : edges)
        {
            if (Nodes_With_No_Incomes.find(EDGE[1]) != Nodes_With_No_Incomes.end())
                Nodes_With_No_Incomes.erase(EDGE[1]);
        }

        vector<int> Ans(Nodes_With_No_Incomes.begin(), Nodes_With_No_Incomes.end());

        return Ans;
    }
};