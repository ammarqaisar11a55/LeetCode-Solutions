class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
        unordered_map<int, int> Mp;

        for (auto x : nums)
            Mp[x]++;

        for (auto x : Mp)
            pq.push({x.second, x.first});

        vector<int> Ans;

        for (int i = 0; i < k; i++)
        {
            Ans.push_back(pq.top().second);
            pq.pop();
        }

        return Ans;
    }
};