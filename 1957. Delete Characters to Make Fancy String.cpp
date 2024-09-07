class Solution
{
public:
    string makeFancyString(string s)
    {

        int current_count = 1;

        string ans;
        ans.push_back(s[0]);

        for (int i = 1; i < s.length(); i++)
        {
            current_count = s[i - 1] == s[i] ? current_count + 1 : 1;

            if (current_count < 3)
                ans.push_back(s[i]);
        }

        return ans;
    }
};