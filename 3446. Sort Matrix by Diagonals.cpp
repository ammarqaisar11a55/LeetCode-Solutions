class Solution
{
public:
    vector<vector<int>> sortMatrix(vector<vector<int>> &Grid)
    {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> Min_mp;
        unordered_map<int, priority_queue<int, vector<int>, less<int>>> Max_mp;

        for (int i = 0; i < Grid.size(); i++)
        {
            for (int j = 0; j < Grid[i].size(); j++)
            {
                if (i - j >= 0)
                {
                    Max_mp[i - j].push(Grid[i][j]);
                }
                else
                {
                    Min_mp[i - j].push(Grid[i][j]);
                }
            }
        }

        for (int i = 0; i < Grid.size(); i++)
        {
            for (int j = 0; j < Grid[i].size(); j++)
            {
                if (i - j >= 0)
                {
                    Grid[i][j] = Max_mp[i - j].top();
                    Max_mp[i - j].pop();
                }
                else
                {
                    Grid[i][j] = Min_mp[i - j].top();
                    Min_mp[i - j].pop();
                }
            }
        }

        return Grid;
    }
};