class Solution
{
public:
    int maximumNumberOfStringPairs(vector<string> &words)
    {

        int count = 0;

        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                if (words[i] == palindromic(words[j]))
                {
                    count++;
                }
            }
        }

        return count;
    }

    string palindromic(string s)
    {
        swap(s[0], s[1]);
        return s;
    }
};