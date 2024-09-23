class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {

        int Ans = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] < nums[j])
                {
                    Ans = max(Ans, nums[j] - nums[i]);
                }
            }
        }

        return Ans;
    }
};