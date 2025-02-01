class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        vector<int> Res;
        int Count_Elements_Equal_to_Pivot = count(nums.begin(), nums.end(), pivot);

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < pivot)
            {
                Res.push_back(nums[i]);
            }
        }

        for (int i = 0; i < Count_Elements_Equal_to_Pivot; i++)
            Res.push_back(pivot);

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > pivot)
            {
                Res.push_back(nums[i]);
            }
        }

        return Res;
    }
};