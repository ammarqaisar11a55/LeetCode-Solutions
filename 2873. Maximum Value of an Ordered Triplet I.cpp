class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {

        vector<long long int> nums1;

        for (int i = 0; i < nums.size(); i++)
        {
            nums1.push_back(nums[i]);
        }

        long long max = LLONG_MIN;

        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = i + 1; j < nums1.size(); j++)
            {
                for (int k = j + 1; k < nums1.size(); k++)
                {
                    if (((nums1[i] - nums1[j]) * nums1[k]) > max)
                    {
                        max = ((nums1[i] - nums1[j]) * nums1[k]);
                    }
                }
            }
        }

        if (max <= 0)
        {
            return 0;
        }

        return max;
    }
};