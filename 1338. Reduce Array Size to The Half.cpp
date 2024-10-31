class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {

        unordered_map<int, int> mp;

        for (auto x : arr)
            mp[x]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;

        for (auto x : mp)
        {
            pq.push({x.second, x.first});
        }

        int currentsize = arr.size();
        int ans = 0;

        while (currentsize > arr.size() / 2 && pq.size() > 0)
        {
            currentsize -= pq.top().first;
            ans++;
            pq.pop();
        }

        return ans;
    }
};