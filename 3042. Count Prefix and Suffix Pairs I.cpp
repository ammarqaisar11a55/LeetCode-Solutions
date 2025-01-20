class Solution
{
public:
    bool isPrefixAndSuffix(string s, string v)
    {
        if (s.length() > v.length())
            return false;

        string pre_fix_of_v = v.substr(0, s.length());
        string post_fix_of_v = v.substr(v.length() - s.length(), s.length());

        return (s == pre_fix_of_v && s == post_fix_of_v) ? true : false;
    }

    int countPrefixSuffixPairs(vector<string> &words)
    {

        int res = 0;

        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                if (isPrefixAndSuffix(words[i], words[j]))
                {
                    res++;
                }
            }
        }

        return res;
    }
};