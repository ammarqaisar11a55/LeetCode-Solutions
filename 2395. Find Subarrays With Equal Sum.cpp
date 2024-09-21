class Solution
{
public:
    bool findSubarrays(vector<int> &nums)
    {

        unordered_set<int> st;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (st.find(nums[i] + nums[i + 1]) != st.end())
            {
                return true;
            }
            else
            {
                st.insert(nums[i] + nums[i + 1]);
            }
        }

        return false;
    }
};