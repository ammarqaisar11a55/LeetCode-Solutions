class Solution
{
public:
    vector<int> numberOfPairs(vector<int> &nums)
    {

        unordered_map<int, int> Counts;

        for (auto x : nums)
        {
            Counts[x]++;
        }

        int pairs = 0;
        int left_over = 0;

        for (auto x : Counts)
        {
            if (x.second % 2 == 0)
                pairs += x.second / 2;

            if (x.second % 2 != 0)
            {
                left_over++;
                x.second--;
                pairs += x.second / 2;
            }
        }

        return {pairs, left_over};
    }
};