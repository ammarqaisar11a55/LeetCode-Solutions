class Solution
{
public:
    void Depth_First_Search_For_Topological_Sort(int SourceNode, unordered_map<int, bool> &Visited, unordered_map<int, list<int>> &AdjList, stack<int> &Topological_Order, bool &Has_Cyclce, unordered_map<int, bool> &DFS_Visited)
    {
        Visited[SourceNode] = true;
        DFS_Visited[SourceNode] = true;

        for (auto Neigh : AdjList[SourceNode])
        {
            if (Visited[Neigh] == false)
            {
                Depth_First_Search_For_Topological_Sort(Neigh, Visited, AdjList, Topological_Order, Has_Cyclce, DFS_Visited);
            }
            else
            {
                if (DFS_Visited[Neigh])
                {
                    Has_Cyclce = true;
                    return;
                }
            }
        }
        DFS_Visited[SourceNode] = false;
        Topological_Order.push(SourceNode);
    }
    //**********************************************************************************************************************************************

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {

        unordered_map<int, list<int>> adjlist;

        for (vector<int> E : prerequisites)
            adjlist[E[1]].push_back(E[0]);

        unordered_map<int, bool> Visited, DFS_Visited;
        stack<int> Topological_Sort;
        bool Hash_Cylce = false;

        for (int i = 0; i < numCourses; i++)
        {
            if (Visited[i] == false)
            {
                Depth_First_Search_For_Topological_Sort(i, Visited, adjlist, Topological_Sort, Hash_Cylce, DFS_Visited);

                if (Hash_Cylce)
                    return {};
            }
        }

        vector<int> Res;

        while (!Topological_Sort.empty())
        {
            Res.push_back(Topological_Sort.top());
            Topological_Sort.pop();
        }

        return Res;
    }
};