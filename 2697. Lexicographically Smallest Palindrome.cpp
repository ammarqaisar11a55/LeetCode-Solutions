class Solution
{
public:
    string makeSmallestPalindrome(string s)
    {

        int st = 0;
        int en = s.length() - 1;

        while (st < en)
        {
            if (s[st] != s[en])
            {
                char smaller = min(s[st], s[en]);
                s[st] = s[en] = smaller;
            }

            st++;
            en--;
        }

        return s;
    }
};