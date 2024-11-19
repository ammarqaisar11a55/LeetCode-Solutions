class Solution
{
public:
    void Solve(int MaxLength, string s, string &ans, unordered_set<string> &st)
    {
        if (s.length() >= MaxLength)
        {
            if (st.find(s) == st.end())
            {
                ans = s;
            }
            return;
        }

        Solve(MaxLength, s + "0", ans, st);
        Solve(MaxLength, s + "1", ans, st);
    }

    string findDifferentBinaryString(vector<string> &nums)
    {

        unordered_set<string> st(nums.begin(), nums.end());

        string ans;

        Solve(nums[0].length(), "1", ans, st);
        Solve(nums[0].length(), "0", ans, st);

        return ans;
    }
};