class Solution
{
public:
    int possibleStringCount(string word)
    {
        int res = 1;

        int consec = 0;

        for (int i = 1; i < word.length(); i++)
        {
            if (word[i] == word[i - 1])
            {
                res++;
            }
        }

        return res;
    }
};