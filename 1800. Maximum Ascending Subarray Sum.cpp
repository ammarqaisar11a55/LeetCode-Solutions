class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        int i = 0;
        int res = 0;
        int single_max = INT_MIN;

        while (i < nums.size())
        {
            int sum = nums[i];
            single_max = max(nums[i], single_max);

            while (i + 1 < nums.size() && nums[i] < nums[i + 1])
            {
                sum += nums[i + 1];
                single_max = max(nums[i], single_max);
                i++;
            }
            single_max = max(nums[i], single_max);
            res = max(res, sum);
            i++;
        }

        return max(res, single_max);
    }
};