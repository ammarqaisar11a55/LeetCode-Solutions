class Solution
{
public:
    int minimumSum(vector<int> &nums)
    {

        int min = INT_MAX;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                for (int k = j + 1; k < nums.size(); k++)
                {
                    if (nums[i] < nums[j] && nums[k] < nums[j])
                    {
                        int ans = nums[i] + nums[j] + nums[k];
                        if (ans < min)
                        {
                            min = ans;
                        }
                    }
                }
            }
        }

        if (min == INT_MAX)
        {
            return -1;
        }

        return min;
    }
};