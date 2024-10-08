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

    int subsetXORSum(vector<int> &nums)
    {

        vector<vector<int>> Ans;
        vector<int> Output;
        int index = 0;
        Solve(nums, index, Output, Ans);

        int sum = 0;

        for (int i = 0; i < Ans.size(); i++)
        {
            int temp = 0;
            for (int j = 0; j < Ans[i].size(); j++)
            {
                temp ^= Ans[i][j];
            }
            sum += temp;
        }

        return sum;
    }
};