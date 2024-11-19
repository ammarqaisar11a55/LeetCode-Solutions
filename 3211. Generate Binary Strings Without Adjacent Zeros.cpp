class Solution
{
public:
    void Solve(int MaxLength, string s, vector<string> &Ans)
    {
        if (s.length() >= MaxLength)
        {
            Ans.push_back(s);
            return;
        }

        if (s.back() == '1')
            Solve(MaxLength, s + "0", Ans);

        Solve(MaxLength, s + "1", Ans);
    }

    vector<string> validStrings(int n)
    {

        vector<string> Ans;

        Solve(n, "1", Ans);
        Solve(n, "0", Ans);

        return Ans;
    }
};