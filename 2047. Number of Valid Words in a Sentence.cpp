class Solution
{
public:
    bool Nodigits(string s)
    {
        for (int i = 0; i < s.length(); i++)
            if (isdigit(s[i]))
                return false;

        return true;
    }

    bool OnlyOneHyphenAndAtCorrectP(string s)
    {
        int count = 0;
        int position = -1;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '-')
            {
                position = i;
                count++;
            }
        }

        if (count == 0)
            return true;

        if (count > 1)
            return false;

        if (position - 1 >= 0 && position + 1 < s.length() && islower(s[position - 1]) && islower(s[position + 1]))
            return true;

        return false;
    }

    bool PunValid(string s)
    {
        int count = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '!' || s[i] == '.' || s[i] == ',')
                count++;
        }

        if (count == 0)
            return true;

        if (count > 1)
            return false;

        return s.back() == '!' || s.back() == '.' || s.back() == ',' ? true : false;
    }

    int countValidWords(string sentence)
    {
        if (sentence.back() != ' ')
            sentence.push_back(' ');

        vector<string> words;
        string single;

        for (int i = 0; i < sentence.length(); i++)
        {
            if (sentence[i] == ' ')
            {
                if (!single.empty())
                {
                    words.push_back(single);
                    single.clear();
                }
            }
            else
            {
                single.push_back(sentence[i]);
            }
        }

        int Count = 0;

        for (int i = 0; i < words.size(); i++)
        {
            if (Nodigits(words[i]) && OnlyOneHyphenAndAtCorrectP(words[i]) && PunValid(words[i]))
                Count++;
        }

        return Count;
    }
};