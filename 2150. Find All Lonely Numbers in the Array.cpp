class Solution
{
public:
    vector<int> findLonely(vector<int> &nums)
    {

        unordered_map<int, int> Mp;

        for (auto x : nums)
            Mp[x]++;

        vector<int> Ans;

        for (int i = 0; i < nums.size(); i++)
        {
            if (Mp.find(nums[i]) != Mp.end() && Mp[nums[i]] == 1 && Mp.find(nums[i] - 1) == Mp.end() && Mp.find(nums[i] + 1) == Mp.end())
                Ans.push_back(nums[i]);
        }

        return Ans;
    }
};