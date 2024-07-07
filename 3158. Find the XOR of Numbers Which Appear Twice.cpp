class Solution
{
public:
    int duplicateNumbersXOR(vector<int> &nums)
    {

        unordered_map<int, int> Freq;

        for (auto x : nums)
            Freq[x]++;

        int ans = 0;

        for (auto x : Freq)
            if (x.second == 2)
                ans ^= x.first;

        return ans;
    }
};