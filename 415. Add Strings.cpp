class Solution
{
public:
    void Solve(string N1, string N2, int carry, string &res)
    {
        if (N1.empty() && N2.empty() && carry == 0)
        {
            return;
        }

        int N1_Last = 0, N2_Last = 0;

        if (!N1.empty())
        {
            N1_Last = N1.back() - '0';
            N1.pop_back();
        }

        if (!N2.empty())
        {
            N2_Last = N2.back() - '0';
            N2.pop_back();
        }

        int Digits_Addition = N1_Last + N2_Last + carry;

        int CarryLeft = Digits_Addition / 10;
        int CarryRight = Digits_Addition % 10;

        res = to_string(CarryRight) + res;

        Solve(N1, N2, CarryLeft, res);
    }

    string addStrings(string num1, string num2)
    {

        string res;
        Solve(num1, num2, 0, res);
        return res;
    }
};