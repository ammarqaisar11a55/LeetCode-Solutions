class Solution
{
public:
    int winningPlayerCount(int n, vector<vector<int>> &pick)
    {

        unordered_map<int, unordered_map<int, int>> Mp;

        for (int i = 0; i < pick.size(); i++)
        {
            Mp[pick[i][0]][pick[i][1]]++;
        }

        int winners = 0;

        for (auto x : Mp)
        {
            for (auto y : x.second)
                if (y.second > x.first)
                {
                    winners++;
                    break;
                }
        }

        return winners;
    }
};