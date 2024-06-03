class Solution
{
public:
    string sortVowels(string s)
    {

        vector<char> vowels;

        for (int i = 0; i < s.length(); i++)
        {
            if (IsVowel(s[i]))
            {
                vowels.push_back(s[i]);
                s[i] = '*';
            }
        }

        sort(vowels.begin(), vowels.end());
        int j = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '*')
            {
                s[i] = vowels[j++];
            }
        }

        return s;
    }

    bool IsVowel(char a)
    {

        if (a == 'A' || a == 'a' || a == 'E' || a == 'e' || a == 'I' || a == 'i' || a == 'O' || a == 'o' || a == 'U' || a == 'u')
        {
            return true;
        }

        return false;
    }
};