class Solution
{
public:
    vector<int> arrayChange(vector<int> &nums, vector<vector<int>> &operations)
    {

        unordered_map<int, int> Mp;

        for (int i = 0; i < nums.size(); i++)
        {
            Mp[nums[i]] = i;
        }

        for (int i = 0; i < operations.size(); i++)
        {
            int old_val = operations[i][0];
            int new_val = operations[i][1];

            int index = Mp[old_val];

            nums[index] = new_val;

            Mp.erase(nums[index]);
            Mp[nums[index]] = index;
        }

        return nums;
    }
};