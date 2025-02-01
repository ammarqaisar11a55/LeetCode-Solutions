class Solution
{
public:
    bool Ans(vector<int> nums)
    {
        sort(nums.begin(), nums.end());

        int Prev_diff = nums[1] - nums[0];

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] - nums[i] != Prev_diff)
                return false;
        }

        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        vector<bool> Res;

        for (int i = 0; i < l.size(); i++)
        {
            vector<int> Sub_Array;

            for (int j = l[i]; j <= r[i]; j++)
            {
                Sub_Array.push_back(nums[j]);
            }

            Res.push_back(Ans(Sub_Array));
        }

        return Res;
    }
};