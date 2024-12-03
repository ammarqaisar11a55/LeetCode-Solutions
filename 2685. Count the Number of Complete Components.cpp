class Solution
{
public:
    void DFS(int Source, int &Nodes_Count, int &Edges_Count, unordered_map<int, list<int>> &AdjacenceyList, unordered_map<int, bool> &Visited)
    {
        Visited[Source] = true;
        Nodes_Count++;

        for (auto X : AdjacenceyList[Source])
        {
            Edges_Count++;
            if (!Visited[X])
            {
                DFS(X, Nodes_Count, Edges_Count, AdjacenceyList, Visited);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {

        unordered_map<int, list<int>> AdjacenceyList;

        for (vector<int> Edge : edges)
        {
            AdjacenceyList[Edge[0]].push_back(Edge[1]);
            AdjacenceyList[Edge[1]].push_back(Edge[0]);
        }

        int Count_Complete_Componenets = 0;
        unordered_map<int, bool> Visited;

        for (int i = 0; i < n; i++)
        {

            if (!Visited[i])
            {
                int Count_Edges = 0;
                int Count_Nodes = 0;
                DFS(i, Count_Nodes, Count_Edges, AdjacenceyList, Visited);
                Count_Edges /= 2;
                Count_Complete_Componenets += (Count_Edges == (Count_Nodes * (Count_Nodes - 1) / 2)) ? 1 : 0;
            }
        }

        return Count_Complete_Componenets;
    }
};