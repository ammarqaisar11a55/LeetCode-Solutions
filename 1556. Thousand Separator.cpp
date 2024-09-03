class Solution
{
public:
    string thousandSeparator(int n)
    {

        string N = to_string(n);

        if (N.length() == 3)
            return N;

        string ans;

        int i = 0;

        for (int k = N.length() - 1; k >= 0; k--)
        {
            i++;
            ans.push_back(N[k]);

            if (i == 3)
            {
                i = 0;
                ans += ".";
            }
        }

        if (ans.length() > 0 && ans.back() == '.')
            ans.pop_back();

        reverse(ans.begin(), ans.end());

        return ans;
    }
};