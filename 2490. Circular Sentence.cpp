class Solution
{
public:
    bool isCircularSentence(string sentence)
    {

        string single;
        vector<string> words;
        sentence.push_back(' ');

        for (int i = 0; i < sentence.length(); i++)
        {
            if (sentence[i] != ' ')
            {
                single.push_back(sentence[i]);
            }
            else
            {
                words.push_back(single);
                single.clear();
            }
        }

        if (words.size() == 1)
        {
            if (words[0][0] == words[0][words[0].length() - 1])
            {
                return true;
            }
            else
                return false;
        }
        else if (words.size() > 1)
        {
            for (int i = 1; i < words.size(); i++)
            {
                if (words[i - 1][words[i - 1].length() - 1] != words[i][0])
                {
                    return false;
                }
            }

            if (words[words.size() - 1][words[words.size() - 1].length() - 1] != words[0][0])
            {
                return false;
            }
            else
                return true;
        }

        return true;
    }
};