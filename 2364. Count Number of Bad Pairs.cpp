class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        unordered_map<int, int> mp;

        long long int Total_Pairs = nums.size() * (nums.size() - 1) / 2;
        long long Good_Pairs = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int Diff = nums[i] - i;

            Good_Pairs += mp[Diff];

            mp[Diff]++;
        }

        return Total_Pairs - Good_Pairs;
    }
};