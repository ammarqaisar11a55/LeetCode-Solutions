class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {

        unordered_set<int> st(nums.begin(), nums.end());

        if (st.find(0) != st.end())
        {
            st.erase(0);
        }

        return st.size();
    }
};