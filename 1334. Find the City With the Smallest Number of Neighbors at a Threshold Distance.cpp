class Solution
{
public:
    int Dijkstra_Algorithm(int Source, int Nodes, unordered_map<int, list<pair<int, int>>> &AdjacencyList, int T_D)
    {
        vector<int> Distances(Nodes, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Min_Heap;

        Distances[Source] = 0;

        Min_Heap.push({Distances[Source], Source});

        while (!Min_Heap.empty())
        {
            int u = Min_Heap.top().second;
            int u_Weight = Min_Heap.top().first;
            Min_Heap.pop();

            for (auto Neighbour : AdjacencyList[u])
            {
                int v = Neighbour.first;
                int v_weight = Neighbour.second;

                if (Distances[u] + v_weight < Distances[v])
                {
                    Distances[v] = Distances[u] + v_weight;
                    Min_Heap.push({Distances[v], v});
                }
            }
        }

        int Count_Nodes_with_Threshold_Distance = 0;

        for (int i = 0; i < Distances.size(); i++)
        {
            if (i == Source)
                continue;

            if (Distances[i] <= T_D)
            {
                Count_Nodes_with_Threshold_Distance++;
            }
        }

        return Count_Nodes_with_Threshold_Distance;
    }

    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        unordered_map<int, list<pair<int, int>>> AdjacencyList;

        for (vector<int> Weighted_Edge : edges)
        {
            int From = Weighted_Edge[0];
            int To = Weighted_Edge[1];
            int Weight = Weighted_Edge[2];

            AdjacencyList[From].push_back({To, Weight});
            AdjacencyList[To].push_back({From, Weight});
        }

        unordered_map<int, int> Nodes_with_Neighbours_at_Threshold_Distance;
        int Min = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            Nodes_with_Neighbours_at_Threshold_Distance[i] = Dijkstra_Algorithm(i, n, AdjacencyList, distanceThreshold);
            Min = min(Min, Nodes_with_Neighbours_at_Threshold_Distance[i]);
        }

        int Res = 0;

        for (auto x : Nodes_with_Neighbours_at_Threshold_Distance)
        {
            if (x.second == Min)
            {
                Res = max(Res, x.first);
            }
        }

        return Res;
    }
};