class Solution
{
public:
    int minimumLength(string s)
    {
        if (s.length() == 1)
            return int(s.length());

        int i = 0;
        int j = s.length() - 1;

        while (i < j)
        {
            if (s[i] == s[j])
            {
                int CommonCharacter = s[i];

                while (j >= i && s[j] == CommonCharacter)
                {
                    s[j] = '*';
                    j--;
                }

                while (i <= j && s[i] == CommonCharacter)
                {
                    s[i] = '*';
                    i++;
                }
            }
            else
            {
                break;
            }
        }

        return int(count(s.begin(), s.end(), 'a') + count(s.begin(), s.end(), 'b') + count(s.begin(), s.end(), 'c'));
    }
};