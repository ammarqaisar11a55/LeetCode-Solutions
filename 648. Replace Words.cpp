class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        string res;
        unordered_set<string> Roots(dictionary.begin(), dictionary.end());

        string single;
        sentence.push_back(' ');

        for (int i = 0; i < sentence.length(); i++)
        {
            if (sentence[i] != ' ')
            {
                single.push_back(sentence[i]);

                if (Roots.find(single) != Roots.end())
                {
                    if (!res.empty())
                        res += " ";
                    res += single;
                    single.clear();

                    while (i + 1 < sentence.length() && sentence[i + 1] != ' ')
                    {
                        i++;
                    }
                }
            }
            else
            {
                if (!single.empty())
                {
                    if (!res.empty())
                        res += " ";
                    res += single;
                    single.clear();
                }
            }
        }

        return res;
    }
};