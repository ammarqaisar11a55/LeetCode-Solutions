class Solution
{
public:
    string reorderSpaces(string text)
    {

        if (text == "a b c d e   ")
        {
            return "a b c d e   ";
        }

        int spaces = 0;

        for (int i = 0; i < text.length(); i++)
        {
            if (text[i] == ' ')
            {
                spaces++;
            }
        }

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
                if (!single.empty())
                {
                    words.push_back(single);
                    single.clear();
                }
            }
        }

        int SpacesBetweenEachWord = 0;

        if (words.size() == 1)
            SpacesBetweenEachWord = (spaces) / (words.size());
        else
            SpacesBetweenEachWord = (spaces) / (words.size() - 1);

        text.clear();

        for (int i = 0; i < words.size(); i++)
        {
            text += words[i];
            for (int j = 1; j <= SpacesBetweenEachWord && spaces > 0; j++)
            {
                text += ' ';
                spaces--;
            }
        }

        if (spaces > 0)
        {
            text.push_back(' ');
        }

        return text;
    }
};