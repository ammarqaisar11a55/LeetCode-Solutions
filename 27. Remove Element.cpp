class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {

        int k = 0;
        vector<int> copy;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                k++;
                copy.push_back(nums[i]);
            }
        }

        nums.clear();
        nums.shrink_to_fit();
        nums = copy;

        return k;
    }
};