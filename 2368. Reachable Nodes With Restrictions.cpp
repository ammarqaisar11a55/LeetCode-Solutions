class Solution
{
public:
    void DFS(int source, unordered_map<int, bool> &visited, unordered_set<int> &Restricted_Nodes, unordered_map<int, vector<int>> &adjList, int &Count)
    {
        visited[source] = true;
        Count++;

        for (int Neighbour : adjList[source])
        {
            if (!visited[Neighbour] && Restricted_Nodes.find(Neighbour) == Restricted_Nodes.end())
            {
                DFS(Neighbour, visited, Restricted_Nodes, adjList, Count);
            }
        }
    }

    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted)
    {

        unordered_set<int> Restricted_Nodes(restricted.begin(), restricted.end());
        unordered_map<int, bool> Visited;

        if (Restricted_Nodes.find(0) != Restricted_Nodes.end())
            return 0;

        unordered_map<int, vector<int>> adjList;
        for (const auto &edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        int Count_reachanleNodes = 0;
        DFS(0, Visited, Restricted_Nodes, adjList, Count_reachanleNodes);

        return Count_reachanleNodes;
    }
};