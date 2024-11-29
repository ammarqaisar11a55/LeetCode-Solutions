class Solution
{
public:
    int edgeScore(vector<int> &edges)
    {

        long long MaxScore = INT_MIN;
        unordered_map<long, long> Nodes_With_Scores;

        for (int i = 0; i < edges.size(); i++)
        {
            Nodes_With_Scores[edges[i]] += i;
            if (Nodes_With_Scores[edges[i]] > MaxScore)
                MaxScore = Nodes_With_Scores[edges[i]];
        }

        int MinNode = INT_MAX;

        for (auto x : Nodes_With_Scores)
        {
            if (x.second == MaxScore && x.first < MinNode)
                MinNode = x.first;
        }

        return MinNode;
    }
};