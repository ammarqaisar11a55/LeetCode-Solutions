class Solution
{
public:
    int countSegments(string s)
    {

        int count = 0;
        s.push_back(' ');

        for (int i = 1; i < s.length(); i++)
        {
            if (s[i - 1] != ' ' && s[i] == ' ')
            {
                count++;
            }
        }

        return count;
    }
};