class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {

        sort(begin(nums), end(nums));

        int s = 0;
        int e = nums.size() - 1;

        int Ans = INT_MIN;

        while (s < e)
        {
            Ans = max(Ans, nums[s] + nums[e]);
            s++;
            e--;
        }

        return Ans;
    }
};