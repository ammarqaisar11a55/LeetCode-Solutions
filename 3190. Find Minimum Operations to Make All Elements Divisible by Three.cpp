class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {

        int OperationCounts = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 3 == 0)
                continue;

            if (nums[i] % 3 != 0)
            {
                if ((nums[i] + 1) % 3 == 0)
                {
                    OperationCounts++;
                }
                else if ((nums[i] - 1) % 3 == 0)
                {
                    OperationCounts++;
                }
            }
        }
        return OperationCounts;
    }
};