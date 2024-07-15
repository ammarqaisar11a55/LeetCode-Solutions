class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {

        unordered_map<int, int> Count;

        for (int i = 0; i < edges.size(); i++)
        {
            for (int j = 0; j < edges[i].size(); j++)
            {
                Count[edges[i][j]]++;
            }
        }

        int ans = 0;
        int temp = 0;

        for (auto x : Count)
        {
            if (x.second > temp)
            {
                temp = x.second;
                ans = x.first;
            }
        }

        return ans;
    }
};