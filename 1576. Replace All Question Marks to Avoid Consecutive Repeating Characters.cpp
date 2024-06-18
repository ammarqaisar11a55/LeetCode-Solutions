class Solution
{
public:
    string modifyString(string s)
    {

        // Modification excluding First and Last character:

        for (int i = 1; i < s.length() - 1; i++)
        {
            if (s[i] == '?')
            {
                s[i] = Modify(s[i], s[i - 1], s[i + 1]);
            }
        }

        if (s[0] == '?')
        {
            s[0] = ModifyForFirstAndLast(s[1]);
        }

        if (s[s.length() - 1] == '?')
        {
            s[s.length() - 1] = ModifyForFirstAndLast(s[s.length() - 2]);
        }

        return s;
    }

    char Modify(char s, char left, char right)
    {
        for (char i = 'a'; i < 'z'; i++)
        {
            if (i != left && i != right)
            {
                return i;
            }
        }

        return ' ';
    }

    char ModifyForFirstAndLast(char a)
    {
        for (char i = 'a'; i < 'z'; i++)
        {
            if (i != a)
            {
                return i;
            }
        }

        return ' ';
    }
};