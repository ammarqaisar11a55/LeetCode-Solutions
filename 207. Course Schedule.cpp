class Solution
{
public:
    void DFS(int Source, unordered_map<int, bool> &Visited, unordered_map<int, bool> &DFS_Visited, unordered_map<int, list<int>> &adjlist, bool &has_cycle)
    {
        Visited[Source] = true;
        DFS_Visited[Source] = true;

        for (auto Neighbour : adjlist[Source])
        {
            if (!Visited[Neighbour])
            {
                DFS(Neighbour, Visited, DFS_Visited, adjlist, has_cycle);
            }
            else
            {
                if (DFS_Visited[Neighbour])
                {
                    has_cycle = true;
                    return;
                }
            }
        }

        DFS_Visited[Source] = false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, list<int>> adj;

        for (vector<int> Edge : prerequisites)
        {
            adj[Edge[1]].push_back(Edge[0]);
        }

        unordered_map<int, bool> Visited, DFS_Visited;
        bool Has_cycle = false;

        for (auto X : adj)
        {
            if (!Visited[X.first])
                DFS(X.first, Visited, DFS_Visited, adj, Has_cycle);

            if (Has_cycle)
                return false;
        }

        return true;
    }
};