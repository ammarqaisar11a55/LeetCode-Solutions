class Solution
{
public:
    double minimumAverage(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<double> averages;

        int start = 0;
        int end = nums.size() - 1;

        while (start < end)
        {
            averages.push_back((nums[start++] + nums[end--]) / 2.0);
        }

        return *min_element(averages.begin(), averages.end());
    }
};
