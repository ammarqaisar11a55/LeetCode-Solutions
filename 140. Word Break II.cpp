class Solution
{
public:
    void Solve(string s, string current_sentence, int index, vector<string> &res, unordered_set<string> Dict)
    {
        if (index >= s.length())
        {
            res.push_back(current_sentence);
            return;
        }

        string temp;

        for (int i = index; i < s.length(); i++)
        {
            temp += s[i];

            if (Dict.find(temp) != Dict.end())
            {
                if (!current_sentence.empty())
                {
                    Solve(s, current_sentence + " " + temp, i + 1, res, Dict);
                }
                else
                    Solve(s, current_sentence + temp, i + 1, res, Dict);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> Dictionary(wordDict.begin(), wordDict.end());
        string current_sentence;
        vector<string> Res;
        Solve(s, "", 0, Res, Dictionary);
        return Res;
    }
};