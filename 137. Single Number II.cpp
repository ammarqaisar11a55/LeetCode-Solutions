class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {

        unordered_map<int, int> FREQ;

        for (auto x : nums)
            FREQ[x]++;

        for (auto x : FREQ)
            if (x.second == 1)
                return x.first;

        return -1;
    }
};