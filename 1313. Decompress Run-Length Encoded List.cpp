class Solution
{
public:
    vector<int> decompressRLElist(vector<int> &nums)
    {

        vector<int> ans;

        for (int i = 0; i < nums.size(); i = i + 2)
        {
            Generator(ans, nums[i], nums[i + 1]);
        }

        return ans;
    }

    void Generator(vector<int> &ans, int freq, int value)
    {
        for (int i = 1; i <= freq; i++)
        {
            ans.push_back(value);
        }
    }
};