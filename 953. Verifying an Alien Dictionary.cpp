class Solution
{
public:
    bool Comparison(string word1, string word2, unordered_map<char, int> mp)
    {
        int minLength = min(int(word1.length()), int(word2.length()));

        for (int i = 0; i < minLength; i++)
        {
            if (word1[i] != word2[i])
            {
                return mp[word1[i]] < mp[word2[i]];
            }
        }

        return word1.length() <= word2.length();
    }

    bool isAlienSorted(vector<string> &words, string order)
    {

        unordered_map<char, int> AlienOrder;

        for (int i = 0; i < order.length(); i++)
        {
            AlienOrder[order[i]] = i;
        }

        for (int i = 0; i < words.size() - 1; i++)
        {
            if (Comparison(words[i], words[i + 1], AlienOrder) == false)
            {
                return false;
            }
        }

        return true;
    }
};