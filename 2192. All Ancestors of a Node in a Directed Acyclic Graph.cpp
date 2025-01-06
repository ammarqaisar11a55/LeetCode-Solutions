class Solution
{
public:
    void DFS(int Current_Parent, int Child, unordered_map<int, list<int>> &AdjList, unordered_map<int, bool> &Visited, vector<vector<int>> &Ans)
    {
        Visited[Child] = true;

        for (int Neighbour : AdjList[Child])
        {
            if (!Visited[Neighbour])
                DFS(Current_Parent, Neighbour, AdjList, Visited, Ans);
        }

        if (Current_Parent != Child)
        {
            Ans[Current_Parent].push_back(Child);
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, list<int>> AdjList;

        for (auto E : edges)
        {
            AdjList[E[0]].push_back(E[1]);
        }
        unordered_map<int, list<int>> Transpose;

        for (auto i : AdjList)
        {
            for (auto j : i.second)
            {
                Transpose[j].push_back(i.first);
            }
        }

        vector<vector<int>> Ans(n);

        for (int i = 0; i < n; i++)
        {
            unordered_map<int, bool> Visited;
            DFS(i, i, Transpose, Visited, Ans);
        }

        for (vector<int> &C : Ans)
        {
            sort(C.begin(), C.end());
        }

        return Ans;
    }
};
/*Optimized: */

class Solution
{
public:
    void DFS(int Current_Parent, int Child, unordered_map<int, list<int>> &AdjList, unordered_map<int, bool> &Visited, vector<vector<int>> &Ans)
    {
        Visited[Child] = true;

        for (int Neighbour : AdjList[Child])
        {
            if (!Visited[Neighbour])
                DFS(Current_Parent, Neighbour, AdjList, Visited, Ans);
        }

        if (Current_Parent != Child)
        {
            Ans[Current_Parent].push_back(Child);
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, list<int>> AdjList;

        for (auto E : edges)
        {
            AdjList[E[1]].push_back(E[0]);
        }

        vector<vector<int>> Ans(n);

        for (int i = 0; i < n; i++)
        {
            unordered_map<int, bool> Visited;
            DFS(i, i, AdjList, Visited, Ans);
        }

        for (vector<int> &C : Ans)
        {
            sort(C.begin(), C.end());
        }

        return Ans;
    }
};