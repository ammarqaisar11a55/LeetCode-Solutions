class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {

        int s = 0;
        int e = nums.size() - 1;
        int mid = (s + e) / 2;

        while (s <= e)
        {
            mid = (s + e) / 2;

            if (target == nums[mid])
            {

                return mid;
            }

            if (target < nums[mid])
            {

                e = mid - 1;
            }

            if (target > nums[mid])
            {

                s = mid + 1;
            }

            mid = (s + e) / 2;
        }

        return s;
    }
};