class Solution
{
public:
    bool isvowel(char x)
    {
        return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' ? true : false;
    }

    int maxVowels(string s, int k)
    {

        int countvowels = 0;
        int maxVowelsInWindow = INT_MIN;

        for (int i = 0; i < k; i++)
        {
            if (isvowel(s[i]))
                countvowels++;
        }

        maxVowelsInWindow = max(maxVowelsInWindow, countvowels);

        for (int i = k; i < s.length(); i++)
        {
            countvowels -= isvowel(s[i - k]) ? 1 : 0;
            countvowels += isvowel(s[i]) ? 1 : 0;

            maxVowelsInWindow = max(maxVowelsInWindow, countvowels);
        }

        return maxVowelsInWindow == INT_MIN ? 0 : maxVowelsInWindow;
    }
};