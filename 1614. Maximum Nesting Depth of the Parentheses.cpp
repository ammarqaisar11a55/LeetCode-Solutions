class Solution
{
public:
    int maxDepth(string s)
    {

        int Maxi = INT_MIN;
        int count = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                count++;
            else if (s[i] == ')')
                count--;

            Maxi = max(Maxi, count);
        }

        return Maxi;
    }
};