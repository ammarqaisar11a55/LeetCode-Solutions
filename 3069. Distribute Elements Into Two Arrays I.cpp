class Solution
{
public:
    vector<int> resultArray(vector<int> &nums)
    {

        vector<int> arr1;
        vector<int> arr2;

        for (int i = 0; i < nums.size(); i++)
        {
            if (arr1.size() == 0)
            {
                arr1.push_back(nums[i]);
                continue;
            }

            if (arr2.size() == 0)
            {
                arr2.push_back(nums[i]);
                continue;
            }

            if (arr1[arr1.size() - 1] > arr2[arr2.size() - 1])
            {
                arr1.push_back(nums[i]);
            }
            else
                arr2.push_back(nums[i]);
        }

        for (int i = 0; i < arr2.size(); i++)
        {
            arr1.push_back(arr2[i]);
        }

        return arr1;
    }
};