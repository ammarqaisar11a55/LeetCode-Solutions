class Solution
{
public:
    string stringHash(string s, int k)
    {

        string res;

        int CurrentSize = 0;
        int HashValues = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (CurrentSize != k)
            {
                HashValues += s[i] - 'a';
                CurrentSize++;
                continue;
            }
            else
            {
                res += ('a' + (HashValues % 26));
                CurrentSize = 1;
                HashValues = s[i] - 'a';
            }
        }

        res += ('a' + (HashValues % 26));

        return res;
    }
};