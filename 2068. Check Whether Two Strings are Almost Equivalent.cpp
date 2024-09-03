class Solution
{
public:
    bool checkAlmostEquivalent(string word1, string word2)
    {

        unordered_map<char, int> W1, W2;

        for (int i = 0; i < word1.length(); i++)
        {
            W1[word1[i]]++;
            W2[word2[i]]++;
        }

        for (char i = 'a'; i <= 'z'; i++)
        {
            int a = W1[i];
            int b = W2[i];

            if (abs(a - b) > 3)
                return false;
        }

        return true;
    }
};