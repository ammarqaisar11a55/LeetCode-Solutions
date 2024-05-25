class Solution
{
public:
    int countKeyChanges(string s)
    {

        int count = 0;

        for (int i = 1; i < s.length(); i++)
        {
            if (s[i - 1] == toupper(s[i]) || s[i - 1] == tolower(s[i]))
            {
                continue;
            }
            else
                count++;
        }
        return count;
    }
};