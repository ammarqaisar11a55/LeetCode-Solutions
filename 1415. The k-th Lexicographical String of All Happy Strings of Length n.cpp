class Solution
{
public:
    void Solve(int Target_Length, vector<string> &Res, string Current_String)
    {
        if (Current_String.length() == Target_Length)
        {
            Res.push_back(Current_String);
            return;
        }

        for (char c = 'a'; c <= 'c'; c++)
        {
            if (Current_String.empty())
            {
                Solve(Target_Length, Res, Current_String + c);
            }
            else if (Current_String.back() != c)
            {
                Solve(Target_Length, Res, Current_String + c);
            }
        }
    }

    string getHappyString(int n, int k)
    {
        vector<string> Res;
        Solve(n, Res, "");

        if (Res.size() < k)
            return "";

        sort(Res.begin(), Res.end());

        return Res[k - 1];
    }
};