class Solution
{
public:
    void DFS(int Source, int &Count_Nodes_of_Componenet, unordered_map<int, list<int>> &AdjacencyList, unordered_map<int, bool> &Visited)
    {
        Visited[Source] = true;
        Count_Nodes_of_Componenet++;

        for (auto Neighbour : AdjacencyList[Source])
        {
            if (!Visited[Neighbour])
            {
                DFS(Neighbour, Count_Nodes_of_Componenet, AdjacencyList, Visited);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>> &edges)
    {

        unordered_map<int, list<int>> AdjacencyList;

        for (vector<int> Edge : edges)
        {
            AdjacencyList[Edge[0]].push_back(Edge[1]);
            AdjacencyList[Edge[1]].push_back(Edge[0]);
        }

        vector<int> Each_Component_Total_Nodes;
        unordered_map<int, bool> Visited;

        for (auto X : AdjacencyList)
        {
            if (!Visited[X.first])
            {
                int Count_Nodes = 0;
                DFS(X.first, Count_Nodes, AdjacencyList, Visited);
                Each_Component_Total_Nodes.push_back(Count_Nodes);
            }
        }

        for (int i = 0; i < n; i++)
            if (!Visited[i])
                Each_Component_Total_Nodes.push_back(1);

        if (Each_Component_Total_Nodes.size() == 1)
            return 0;

        long long total_nodes = accumulate(Each_Component_Total_Nodes.begin(), Each_Component_Total_Nodes.end(), 0LL, plus<int>());

        long long res = 0;

        for (int ComponenetNodes : Each_Component_Total_Nodes)
        {
            res += ComponenetNodes * (total_nodes - ComponenetNodes);
            total_nodes -= ComponenetNodes;
        }

        return res;
    }
};