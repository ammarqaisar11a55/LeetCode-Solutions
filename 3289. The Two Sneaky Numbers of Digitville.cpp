class Solution
{
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {

        unordered_map<int, int> Mp;

        for (auto x : nums)
            Mp[x]++;

        vector<int> Ans;

        for (auto x : Mp)
            if (x.second == 2)
                Ans.push_back(x.first);

        return Ans;
    }
};