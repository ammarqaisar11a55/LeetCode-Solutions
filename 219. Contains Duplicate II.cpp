class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {

        int i = 0;
        int j = 0;
        unordered_set<int> st;

        while (j < nums.size())
        {
            if (abs(i - j) > k)
            {
                st.erase(nums[i]);
                i++;
            }

            if (st.find(nums[j]) != st.end())
                return true;

            st.insert(nums[j]);
            j++;
        }

        return false;
    }
};