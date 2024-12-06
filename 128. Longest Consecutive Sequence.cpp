class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {

        unordered_set<int> st(nums.begin(), nums.end());
        int longestsequence = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (st.find(nums[i] - 1) == st.end())
            {
                int currentnumber = nums[i];
                int currentsequence = 1;

                while (st.find(currentnumber + 1) != st.end())
                {
                    currentnumber++;
                    currentsequence++;
                }

                longestsequence = max(longestsequence, currentsequence);
            }
        }

        return longestsequence;
    }
};