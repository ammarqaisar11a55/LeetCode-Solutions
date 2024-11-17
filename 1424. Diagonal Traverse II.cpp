class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {

        unordered_map<int, vector<int>> Mp;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < nums[i].size(); j++)
            {
                Mp[i + j].push_back(nums[i][j]);
            }
        }

        vector<int> Ans;

        int RowColSum = 0;

        while (Mp.find(RowColSum) != Mp.end())
        {
            for (int x : Mp[RowColSum])
                Ans.push_back(x);

            RowColSum++;
        }

        return Ans;
    }
};