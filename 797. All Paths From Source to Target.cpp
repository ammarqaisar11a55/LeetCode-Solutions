class Solution
{
public:
    void dfs(int source, int target, vector<int> &Path, vector<vector<int>> &Ans, unordered_map<int, list<int>> &AdjacencyList)
    {
        Path.push_back(source);

        if (source == target)
        {
            Ans.push_back(Path);
        }
        else
        {
            for (int neighbour : AdjacencyList[source])
            {
                dfs(neighbour, target, Path, Ans, AdjacencyList);
            }
        }

        Path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {

        unordered_map<int, list<int>> AdjacencyList;

        for (int i = 0; i < graph.size(); i++)
        {
            for (int j : graph[i])
            {
                AdjacencyList[i].push_back(j);
            }
        }

        vector<vector<int>> Ans;
        vector<int> SinglePath;

        dfs(0, graph.size() - 1, SinglePath, Ans, AdjacencyList);

        return Ans;
    }
};