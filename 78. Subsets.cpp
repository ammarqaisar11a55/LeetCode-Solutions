class Solution
{
public:
    void Solve(vector<int> nums, int index, vector<int> Output, vector<vector<int>> &Ans)
    {
        // Base Case:
        if (index >= nums.size())
        {
            Ans.push_back(Output);
            return;
        }

        // Exclude:
        Solve(nums, index + 1, Output, Ans);

        // Include:
        Output.push_back(nums[index]);
        Solve(nums, index + 1, Output, Ans);
    }

    //**********************************************
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> Ans;
        vector<int> Output;
        int index = 0;
        Solve(nums, index, Output, Ans);
        return Ans;
    }
};