class Solution
{
public:
    int maximumStrongPairXor(vector<int> &nums)
    {

        int Ans = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (abs(nums[i] - nums[j]) <= min(nums[i], nums[j]))
                {
                    Ans = max(Ans, nums[i] ^ nums[j]);
                }
            }
        }

        return Ans;
    }
};