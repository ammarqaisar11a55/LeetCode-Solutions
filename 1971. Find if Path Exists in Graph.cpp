class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {

        unordered_map<int, list<int>> AdjList;

        for (vector<int> EDGE : edges)
        {
            int u = EDGE[0];
            int v = EDGE[1];

            AdjList[u].push_back(v);
            AdjList[v].push_back(u);
        }

        // BFS:

        unordered_map<int, bool> Visited;

        queue<int> q;
        q.push(source);
        Visited[source] = true;

        while (!q.empty())
        {
            int Temp = q.front();
            q.pop();

            if (Temp == destination)
                return true;

            for (auto x : AdjList[Temp])
            {
                if (Visited[x] == false)
                {
                    Visited[x] = true;
                    q.push(x);
                }
            }
        }

        return false;
    }
};