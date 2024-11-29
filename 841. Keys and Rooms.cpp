class Solution
{
public:
    void DFS(int source, unordered_map<int, list<int>> &Adjlist, unordered_map<int, bool> &Visited)
    {
        Visited[source] = true;

        for (auto Neighbour : Adjlist[source])
        {
            if (!Visited[Neighbour])
            {
                DFS(Neighbour, Adjlist, Visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {

        unordered_map<int, list<int>> AdjacencyList;

        for (int i = 0; i < rooms.size(); i++)
        {
            for (int j : rooms[i])
            {
                AdjacencyList[i].push_back(j);
            }
        }

        unordered_map<int, bool> visited;

        DFS(0, AdjacencyList, visited);

        for (int i = 0; i < rooms.size(); i++)
        {
            if (visited.find(i) == visited.end())
                return false;
        }

        return true;
    }
};