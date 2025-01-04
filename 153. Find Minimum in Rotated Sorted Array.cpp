class Solution
{
public:
    int findMin(vector<int> &nums)
    {

        int res = INT_MAX;

        int s = 0;
        int e = nums.size() - 1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            res = min(res, nums[mid]);

            if (nums[mid] > nums[e])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }

        return res;
    }
};