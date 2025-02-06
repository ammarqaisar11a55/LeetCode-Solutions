class Solution
{
public:
    int tupleSameProduct(vector<int> &nums)
    {
        unordered_map<int, int> Products_Freq;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                Products_Freq[nums[i] * nums[j]]++;
            }
        }

        int res = 0;

        for (auto X : Products_Freq)
        {
            if (X.second > 1)
            {
                res += 8 * (X.second * (X.second - 1) / 2);
            }
        }

        return res;
    }
};