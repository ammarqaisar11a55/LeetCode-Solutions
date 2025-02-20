class Solution
{
public:
    bool canSortArray(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size() - 1 - i; j++)
            {
                if (nums[j] > nums[j + 1])
                {
                    if (__builtin_popcount(nums[j]) == __builtin_popcount(nums[j + 1]))
                        swap(nums[j], nums[j + 1]);
                }
            }
        }

        return is_sorted(nums.begin(), nums.end());
    }
};