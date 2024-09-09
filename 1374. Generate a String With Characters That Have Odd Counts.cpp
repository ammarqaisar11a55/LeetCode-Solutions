class Solution
{
public:
    string generateTheString(int n)
    {

        string ans;

        for (int i = 1; i < n; i++)
            ans += 'a';

        return n % 2 == 0 ? ans + 'b' : ans + 'a';
    }
};