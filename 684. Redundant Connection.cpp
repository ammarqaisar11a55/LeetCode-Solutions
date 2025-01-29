class Solution
{
public:
    int FindingParents(vector<int> &Parents, int Node)
    {
        if (Parents[Node] == Node)
        {
            return Node;
        }

        return Parents[Node] = FindingParents(Parents, Parents[Node]);
    }

    bool UnionSet(int U, int V, vector<int> &Parents, vector<int> &Ranks)
    {
        int U_Parent = FindingParents(Parents, U);
        int V_Parent = FindingParents(Parents, V);

        if (U_Parent == V_Parent)
            return false;

        if (U_Parent != V_Parent)
        {
            if (Ranks[U_Parent] < Ranks[V_Parent])
            {
                Parents[U_Parent] = V_Parent;
            }
            else if (Ranks[U_Parent] > Ranks[V_Parent])
            {
                Parents[V_Parent] = U_Parent;
            }
            else
            {
                Parents[U_Parent] = V_Parent;
                Ranks[V_Parent]++;
            }
        }
        return true;
    }

    vector<int> Kruskals_Algorithm(vector<vector<int>> &Edges)
    {
        vector<int> Parents(Edges.size() + 1);
        vector<int> Ranks(Edges.size() + 1, 0);

        for (int i = 1; i < Parents.size(); i++)
        {
            Parents[i] = i;
        }

        for (int i = 0; i < Edges.size(); i++)
        {

            if (!UnionSet(Edges[i][0], Edges[i][1], Parents, Ranks))
            {
                return {Edges[i][0], Edges[i][1]};
            }
        }

        return {};
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        return Kruskals_Algorithm(edges);
    }
};