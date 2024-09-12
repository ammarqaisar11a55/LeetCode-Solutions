class Solution
{
public:
    int numberOfSpecialChars(string word)
    {

        unordered_map<char, int> Mp_Upper, Mp_Lower;
        unordered_set<char> Lower_Set;

        for (int i = 0; i < word.length(); i++)
        {
            if (isupper(word[i]) && Mp_Upper.find(word[i]) == Mp_Upper.end())
            {
                Mp_Upper[word[i]] = i;
            }

            if (islower(word[i]))
            {
                Mp_Lower[word[i]] = i;
                Lower_Set.insert(word[i]);
            }
        }

        int count = 0;

        for (auto it = Lower_Set.begin(); it != Lower_Set.end(); it++)
        {
            if (Mp_Upper.find(toupper(*it)) != Mp_Upper.end() && Mp_Lower[*it] < Mp_Upper[toupper(*it)])
                count++;
        }

        return count;
    }
};