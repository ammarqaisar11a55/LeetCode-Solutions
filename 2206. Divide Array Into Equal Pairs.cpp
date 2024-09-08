class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {

        unordered_map<int, int> Mp;

        for (auto x : nums)
            Mp[x]++;

        for (auto x : Mp)
            if (x.second % 2 != 0)
                return false;

        return true;
    }
};