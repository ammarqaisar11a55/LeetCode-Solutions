class Solution
{
public:
    void Solve(string a, string b, int carry, string &res)
    {
        if (a.empty() && b.empty() && carry == 0)
            return;

        int a_last = 0;
        int b_last = 0;

        if (a.empty() == false)
        {
            a_last = a.back() - '0';
            a.pop_back();
        }
        if (b.empty() == false)
        {
            b_last = b.back() - '0';
            b.pop_back();
        }

        int total = carry + a_last + b_last;

        if (total == 1 || total == 0)
        {
            res = to_string(total) + res;
            Solve(a, b, 0, res);
        }
        else if (total == 2)
        {
            res = "0" + res;
            Solve(a, b, 1, res);
        }
        else
        {
            res = "1" + res;
            Solve(a, b, 1, res);
        }
    }

    string addBinary(string a, string b)
    {

        string res;
        Solve(a, b, 0, res);

        return res;
    }
};