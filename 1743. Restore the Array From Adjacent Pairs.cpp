class Solution
{
public:
    void DFS(int source, unordered_map<int, bool> &Visisted, unordered_map<int, list<int>> &AdjacencyList, vector<int> &Ans)
    {
        Ans.push_back(source);
        Visisted[source] = true;

        for (auto Neighbour : AdjacencyList[source])
        {
            if (Visisted[Neighbour] == false)
            {
                DFS(Neighbour, Visisted, AdjacencyList, Ans);
            }
        }
    }

    vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
    {

        unordered_map<int, list<int>> AdjacencyList;
        unordered_map<int, int> Counts;

        for (vector<int> Edge : adjacentPairs)
        {
            Counts[Edge[0]]++;
            Counts[Edge[1]]++;
            AdjacencyList[Edge[0]].push_back(Edge[1]);
            AdjacencyList[Edge[1]].push_back(Edge[0]);
        }

        int Root = 0;

        for (auto x : Counts)
        {
            if (x.second == 1)
            {
                Root = x.first;
                break;
            }
        }

        vector<int> Ans;
        unordered_map<int, bool> Visited;
        DFS(Root, Visited, AdjacencyList, Ans);
        return Ans;
    }
};