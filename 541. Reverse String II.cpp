class Solution
{
public:
    string reverseStr(string s, int k)
    {

        for (int i = 0; i < s.length(); i += 2 * k)
        {
            int start = i;
            int end = min((int)s.length() - 1, start + k - 1);

            while (start < end)
            {
                swap(s[start++], s[end--]);
            }
        }

        return s;
    }
};