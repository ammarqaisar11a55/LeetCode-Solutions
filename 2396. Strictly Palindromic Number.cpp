class Solution
{
public:
    bool isStrictlyPalindromic(int n)
    {
        return false;
    }
};

class Solution
{
public:
    bool Check(int Number, int Base)
    {
        string representation;

        while (Number > 0)
        {
            representation += to_string(Number % Base);
            Number /= Base;
        }

        int i = 0;
        int j = representation.size() - 1;

        cout << "Number: " << Number << " -> Base -> " << Base << " -> " << representation << endl;

        while (i < j)
        {
            if (representation[i] != representation[j])
                return false;

            i++;
            j--;
        }

        return true;
    }

    bool isStrictlyPalindromic(int n)
    {
        for (int i = 2; i <= n - 2; i++)
            if (!Check(n, i))
                return false;

        return true;
    }
};