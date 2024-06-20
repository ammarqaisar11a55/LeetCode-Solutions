class Solution
{
public:
    bool isFascinating(int n)
    {

        int n2 = n * 2;
        int n3 = n * 3;

        string N = to_string(n) + to_string(n2) + to_string(n3);

        if (N.length() != 9)
        {
            return false;
        }

        sort(N.begin(), N.end());

        int j = 0;

        for (char i = '1'; i <= '9'; i++)
        {
            if (i != N[j++])
            {
                return false;
            }
        }

        return true;
    }
};