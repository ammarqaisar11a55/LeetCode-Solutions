class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {

        unordered_map<int, int> Mp;

        int a;

        for (auto x : grid)
            for (auto y : x)
            {
                Mp[y]++;

                if (Mp[y] == 2)
                    a = y;
            }

        int b;

        for (int i = 1; i <= grid.size() * grid.size(); i++)
        {
            if (Mp.find(i) == Mp.end())
            {
                b = i;
                break;
            }
        }

        return {a, b};
    }
};