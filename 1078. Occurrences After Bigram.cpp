class Solution
{
public:
    vector<string> findOcurrences(string text, string first, string second)
    {

        vector<string> words;
        string single;

        text.push_back(' ');

        for (int i = 0; i < text.length(); i++)
        {
            if (text[i] != ' ')
            {
                single.push_back(text[i]);
            }
            else
            {
                words.push_back(single);
                single.clear();
            }
        }

        vector<string> answer;

        for (int i = 0; i < words.size() - 2; i++)
        {
            if (words[i] == first && words[i + 1] == second && i < words.size())
            {
                answer.push_back(words[i + 2]);
            }
        }

        return answer;
    }
};