class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {

        double ans = 0;
        double tempsum = 0;

        for (int i = 0; i < k; i++)
        {
            tempsum += nums[i];
        }

        ans = tempsum / k;

        for (int i = k; i < nums.size(); i++)
        {
            tempsum -= nums[i - k];
            tempsum += nums[i];
            ans = max(ans, tempsum / k);
        }

        return ans;
    }
};