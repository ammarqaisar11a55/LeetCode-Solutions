class Solution
{
public:
    int ArrayBinarySearchFirst(vector<int> arr, int key)
    {
        int start = 0;
        int end = arr.size() - 1;
        int ans = -1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (arr[mid] == key)
            {
                ans = mid;
                end = mid - 1;
            }

            if (key > arr[mid])
                start = mid + 1;

            if (key < arr[mid])
                end = mid - 1;
        }

        return ans;

        // Time Complexity : O(log N)
        // Space Complexity : O(1)
    }

    int ArrayBinarySearchSecond(vector<int> arr, int key)
    {
        int start = 0;
        int end = arr.size() - 1;
        int ans = -1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (arr[mid] == key)
            {
                ans = mid;
                start = mid + 1;
            }

            if (key > arr[mid])
                start = mid + 1;

            if (key < arr[mid])
                end = mid - 1;
        }

        return ans;

        // Time Complexity : O(log N)
        // Space Complexity : O(1)
    }

    //*************
    vector<int> searchRange(vector<int> &nums, int target)
    {

        int ans1 = ArrayBinarySearchFirst(nums, target);
        int ans2 = ArrayBinarySearchSecond(nums, target);

        return {ans1, ans2};
    }
};