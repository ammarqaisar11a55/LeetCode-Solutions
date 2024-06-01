class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            if (!Is_There(nums, nums[i], i))
            {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }

    bool Is_There(vector<int> &nums, int n, int pos_of_current)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == n && i != pos_of_current)
            {
                return true;
            }
        }

        return false;
    }
};