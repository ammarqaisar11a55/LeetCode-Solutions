class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {

        unordered_set<int> st(nums.begin(), nums.end());

        vector<int> ans;

        for (int i = 1; i <= nums.size(); i++)
            if (st.find(i) == st.end())
                ans.push_back(i);

        return ans;
    }
};

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {

        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]) - 1;

            if (nums[index] > 0)
                nums[index] *= -1;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                ans.push_back(i + 1);
        }

        return ans;
    }
};