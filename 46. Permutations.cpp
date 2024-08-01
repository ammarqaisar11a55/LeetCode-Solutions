class Solution
{
public:
    void Solve(vector<int> nums, int index, vector<vector<int>> &Ans)
    {
        if (index >= nums.size())
        {
            Ans.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            Solve(nums, index + 1, Ans);
            swap(nums[index], nums[i]);
        }
    }

    //**********************************************
    vector<vector<int>> permute(vector<int> &nums)
    {

        vector<vector<int>> Ans;
        int index = 0;
        Solve(nums, index, Ans);
        return Ans;
    }
};