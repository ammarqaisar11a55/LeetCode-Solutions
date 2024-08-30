class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {

        unordered_map<int, int> Mp;

        for (auto x : nums)
            Mp[x]++;

        sort(nums.begin(), nums.end(), [&Mp](int a, int b)
             {
             if (Mp[a] == Mp[b])
                 return a > b;

             return Mp[a] < Mp[b]; });

        return nums;
    }
};