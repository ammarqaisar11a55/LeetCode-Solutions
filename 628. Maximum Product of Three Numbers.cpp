class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {

        int ans = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                for (int k = 0; k < nums.size(); k++)
                {
                    if (i != j && i != k && j != k)
                    {
                        ans = max(ans, nums[i] * nums[j] * nums[k]);
                    }
                }
            }
        }

        return ans;
    }
};

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());

        return max(nums[0] * nums[1] * nums[nums.size() - 1], nums[nums.size() - 1 - 1 - 1] * nums[nums.size() - 1 - 1] * nums[nums.size() - 1]);
    }
};

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {

        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;

        int min1 = INT_MAX;
        int min2 = INT_MAX;

        for (int i = 0; i < nums.size(); i++)
        {
            // Find Maximums:
            if (nums[i] > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if (nums[i] > max2)
            {
                max3 = max2;
                max2 = nums[i];
            }
            else if (nums[i] > max3)
            {
                max3 = nums[i];
            }

            // Find Minimums:
            if (nums[i] < min1)
            {
                min2 = min1;
                min1 = nums[i];
            }
            else if (nums[i] < min2)
            {
                min2 = nums[i];
            }
        }

        return max(max1 * max2 * max3, max1 * min1 * min2);
    }
};