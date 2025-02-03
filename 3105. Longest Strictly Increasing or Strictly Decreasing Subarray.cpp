class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        int longest_increasing = 1;
        int longest_decreasing = 1;

        int res = 0;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] < nums[i + 1])
            {
                longest_increasing++;
            }
            else
            {
                res = max(res, longest_increasing);
                longest_increasing = 1;
            }

            res = max(res, longest_increasing);
        }

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                longest_decreasing++;
            }
            else
            {
                res = max(res, longest_decreasing);
                longest_decreasing = 1;
            }

            res = max(res, longest_decreasing);
        }

        return max(1, res);
    }
};