class Solution
{
public:
    vector<int> findColumnWidth(vector<vector<int>> &grid)
    {

        unordered_map<int, int> mp;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                string temp = to_string(grid[i][j]);
                mp[j] = max(mp[j], (int)temp.length());
            }
        }

        vector<int> ANS(grid[0].size());

        for (auto X : mp)
        {
            ANS[X.first] = X.second;
        }

        return ANS;
    }
};