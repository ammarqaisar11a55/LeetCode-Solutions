int networkDelayTime(vector<vector<int>> times, int n, int k)
{
    unordered_map<int, list<pair<int, int>>> AdjacencyList;

    for (vector<int> Edge : times)
    {
        int FromNode = Edge[0];
        int ToNode = Edge[1];
        int Time = Edge[2];
        AdjacencyList[FromNode].push_back({ToNode, Time});
    }

    vector<int> Distances(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Min_Heap;
    int Source = k;
    Distances[Source] = 0;

    Min_Heap.push({Distances[Source], k});

    while (!Min_Heap.empty())
    {
        int U = Min_Heap.top().second;
        int U_Dist = Min_Heap.top().first;

        Min_Heap.pop();

        for (auto Neighbour : AdjacencyList[U])
        {
            int V = Neighbour.first;
            int V_Weight = Neighbour.second;

            if (Distances[U] + V_Weight < Distances[V])
            {
                Distances[V] = Distances[U] + V_Weight;
                Min_Heap.push({Distances[V], V});
            }
        }
    }

    int MaxDistance = INT_MIN;

    for (int i = 1; i < Distances.size(); i++)
    {
        if (i == Source)
            continue;

        if (Distances[i] == INT_MAX)
            return -1;

        MaxDistance = max(MaxDistance, Distances[i]);
    }

    return MaxDistance;
}