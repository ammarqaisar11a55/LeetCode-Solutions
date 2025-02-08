class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        int T_Pointer = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (T_Pointer < t.length() && t[T_Pointer] == s[i])
            {
                T_Pointer++;
            }
        }

        return t.length() - T_Pointer;
    }
};