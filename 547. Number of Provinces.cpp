class Solution
{
public:
    void BFS(unordered_map<int, bool> &visited, int source, unordered_map<int, list<int>> adjlist)
    {
        queue<int> q;
        visited[source] = true;
        q.push(source);

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (auto x : adjlist[front])
            {
                if (visited[x] == false)
                {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {

        unordered_map<int, list<int>> adjlist;

        for (int i = 0; i < isConnected.size(); i++)
        {
            for (int j = 0; j < isConnected.size(); j++)
            {
                if (isConnected[i][j] == 1)
                {
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }

        unordered_map<int, bool> visited;
        int count = 0;

        for (auto x : adjlist)
        {
            if (visited[x.first] == false)
            {
                BFS(visited, x.first, adjlist);
                count++;
            }
        }

        return count;
    }
};