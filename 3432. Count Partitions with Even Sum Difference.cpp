class Solution
{
public:
    int countPartitions(vector<int> &nums)
    {
        int Complete_Right_Sum = accumulate(nums.begin(), nums.end(), 0, plus<int>());
        int Count = 0;
        int Left_Sum = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            Left_Sum += nums[i];
            Complete_Right_Sum -= nums[i];

            if ((Left_Sum - Complete_Right_Sum) % 2 == 0)
            {
                Count++;
            }
        }

        return Count;
    }
};