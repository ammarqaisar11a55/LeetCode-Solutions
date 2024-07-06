class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {

        unordered_map<int, int> Freq;

        for (auto x : nums)
        {
            Freq[x]++;
        }

        // Max Freq:

        int max = 0;

        for (auto x : Freq)
        {
            if (x.second > max)
                max = x.second;
        }

        // Add the elements with max freq:

        int ans = 0;

        for (auto x : Freq)
            if (x.second == max)
                ans += x.second;

        return ans;
    }
};