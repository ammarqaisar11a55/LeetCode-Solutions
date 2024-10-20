class Solution
{
public:
    int minMaxGame(vector<int> &nums)
    {

        if (nums.size() == 1)
            return nums[0];

        vector<int> newNum(nums.size() / 2);

        for (int i = 0; i < nums.size() / 2; i++)
        {
            if (i & 1)
            {
                newNum[i] = max(nums[2 * i], nums[2 * i + 1]);
            }
            else
            {
                newNum[i] = min(nums[2 * i], nums[2 * i + 1]);
            }
        }

        int ans = minMaxGame(newNum);

        return ans;
    }
};