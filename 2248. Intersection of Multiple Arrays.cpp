class Solution
{
public:
    vector<int> intersection(vector<vector<int>> &nums)
    {

        map<int, int> Mp;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums[i].size(); j++)
            {
                Mp[nums[i][j]]++;
            }
        }

        vector<int> Ans;

        for (auto x : Mp)
        {
            if (x.second == nums.size())
                Ans.push_back(x.first);
        }

        return Ans;
    }
};