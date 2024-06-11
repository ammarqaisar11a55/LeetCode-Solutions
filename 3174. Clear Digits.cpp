class Solution
{
public:
    string clearDigits(string s)
    {

        for (int i = 1; i < s.length(); i++)
        {
            if (isalpha(s[i - 1]) && isdigit(s[i]))
            {
                s.erase(s.begin() + (i));
                s.erase(s.begin() + i - 1);
                i = 0;
            }
        }

        return s;
    }
};