class Solution
{
public:
    void Solve(string N1, string N2, int carry, vector<int> &res)
    {
        if (N1.empty() && N2.empty() && carry == 0)
        {
            return;
        }

        int N1_Last = 0;
        int N2_Last = 0;

        if (N1.empty() == false)
        {
            N1_Last = N1.back() - '0';
            N1.pop_back();
        }

        if (N2.empty() == false)
        {
            N2_Last = N2.back() - '0';
            N2.pop_back();
        }

        int Sum = carry + N1_Last + N2_Last;

        res.push_back(Sum % 10);
        Solve(N1, N2, Sum / 10, res);
    }

    vector<int> addToArrayForm(vector<int> &num, int k)
    {

        string N1 = "";
        string N2 = to_string(k);
        vector<int> res;

        for (int c : num)
        {
            N1 += c + '0';
        }
        Solve(N1, N2, 0, res);
        reverse(res.begin(), res.end());
        return res;
    }
};