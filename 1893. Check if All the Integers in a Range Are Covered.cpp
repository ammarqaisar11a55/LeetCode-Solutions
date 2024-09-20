class Solution
{
public:
    bool isCovered(vector<vector<int>> &ranges, int left, int right)
    {

        unordered_set<int> Ranges;

        for (int i = 0; i < ranges.size(); i++)
        {
            for (int k = ranges[i][0]; k <= ranges[i][1]; k++)
            {
                Ranges.insert(k);
            }
        }

        for (int i = left; i <= right; i++)
        {
            if (Ranges.find(i) == Ranges.end())
                return false;
        }

        return true;
    }
};