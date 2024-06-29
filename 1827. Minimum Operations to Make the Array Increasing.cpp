class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int Operations = 0;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            while (nums[i] >= nums[i + 1])
            {
                nums[i + 1] += 1;
                Operations++;
            }
        }

        return Operations;
    }
};