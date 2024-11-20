class Solution
{
public:
    void Solve(int limit, string s, int leftcount, int rightcount, vector<string> &res)
    {
        if (leftcount == limit && rightcount == limit)
        {
            res.push_back(s);
            return;
        }

        if (leftcount < limit)
        {
            Solve(limit, s + "(", leftcount + 1, rightcount, res);
        }

        if (rightcount < leftcount)
        {
            Solve(limit, s + ")", leftcount, rightcount + 1, res);
        }
    }

    vector<string> generateParenthesis(int n)
    {

        vector<string> res;
        Solve(n, "", 0, 0, res);
        return res;
    }
};