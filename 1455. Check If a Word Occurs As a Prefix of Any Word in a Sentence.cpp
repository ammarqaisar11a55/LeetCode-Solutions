class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {

        string single;
        int word_count = 1;

        for (int i = 0; i < sentence.length(); i++)
        {
            if (isalpha(sentence[i]))
            {
                single.push_back(sentence[i]);

                if (single.length() == searchWord.length() && single == searchWord)
                    return word_count;
            }
            else
            {
                word_count++;
                single.clear();
            }
        }
        return -1;
    }
};