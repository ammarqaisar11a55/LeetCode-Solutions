class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {

        long fmax = *max_element(nums.begin(), nums.end());
        long long smax = LLONG_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > smax && nums[i] < fmax)
            {
                smax = nums[i];
            }
        }

        long long tmax = LLONG_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > tmax && nums[i] < fmax && nums[i] < smax)
            {
                tmax = nums[i];
            }
        }

        vector<int> ans;
        ans.push_back(fmax);

        if (smax != LLONG_MIN)
        {
            ans.push_back(smax);
        }

        if (tmax != LLONG_MIN)
        {
            ans.push_back(tmax);
        }

        if (ans.size() == 3)
        {
            return *min_element(ans.begin(), ans.end());
        }

        if (ans.size() == 2)
        {
            return *max_element(ans.begin(), ans.end());
        }

        return ans[0];
    }
};