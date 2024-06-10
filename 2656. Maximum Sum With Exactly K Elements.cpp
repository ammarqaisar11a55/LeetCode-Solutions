class Solution
{
public:
    int maximizeSum(vector<int> &nums, int k)
    {

        sort(nums.begin(), nums.end());

        int max = nums[nums.size() - 1];

        int ans = 0;

        for (int i = 1; i <= k; i++)
        {
            ans = ans + max;
            max++;
        }

        return ans;
    }
};