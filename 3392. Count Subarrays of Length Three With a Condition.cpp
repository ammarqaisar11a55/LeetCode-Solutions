class Solution
{
public:
    int countSubarrays(vector<int> &nums)
    {
        int count = 0;

        for (int i = 1; i < nums.size() - 1; i++)
        {
            int first_thir = nums[i - 1] + nums[i + 1];
            int second = nums[i];

            if ((first_thir) * 2 == second)
                count++;
        }

        return count;
    }
};