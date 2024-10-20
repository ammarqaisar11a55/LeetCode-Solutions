class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {

        int sum = 0;

        vector<int> Ans(queries.size());

        for (int x : nums)
        {
            if ((x & 1) != 1)
            {
                sum += x;
            }
        }

        for (int i = 0; i < queries.size(); i++)
        {
            int index = queries[i][1];
            int value = queries[i][0];

            if (nums[index] % 2 == 0)
            {
                sum -= nums[index];
            }

            nums[index] += value;

            if (nums[index] % 2 == 0)
            {
                sum += nums[index];
            }

            Ans[i] = sum;
        }

        return Ans;
    }
};