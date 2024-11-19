class Solution
{
public:
    void Solve(string s, vector<string> &Ans, int index)
    {
        if (index >= s.length())
        {
            Ans.push_back(s);
            return;
        }

        Solve(s, Ans, index + 1);

        if (isalpha(s[index]))
        {
            s[index] = islower(s[index]) ? toupper(s[index]) : tolower(s[index]);
            Solve(s, Ans, index + 1);
        }
    }

    vector<string> letterCasePermutation(string s)
    {

        vector<string> Ans;

        Solve(s, Ans, 0);

        return Ans;
    }
};