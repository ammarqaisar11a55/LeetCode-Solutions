class Solution
{
public:
    vector<string> printVertically(string s)
    {

        s.push_back(' ');
        vector<string> words;
        string single;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ')
            {
                single.push_back(s[i]);
            }
            else
            {
                words.push_back(single);
                single.clear();
            }
        }

        vector<string> answer;

        int rounds = 0;

        for (int i = 0; i < words.size(); i++)
        {
            if (words[i].length() > rounds)
            {
                rounds = words[i].length();
            }
        }

        for (int i = 0; i < rounds; i++)
        {
            for (int j = 0; j < words.size(); j++)
            {
                if (words[j][0] >= 'A' && words[j][0] <= 'Z')
                {
                    single.push_back(words[j][0]);
                    words[j].erase(words[j].begin());
                }
                else
                    single.push_back(' ');
            }

            answer.push_back(single);
            single.clear();
        }

        for (int i = 0; i < answer.size(); i++)
        {
            for (int j = answer[i].length() - 1; j >= 0; j--)
            {
                if (answer[i][j] == ' ')
                {
                    answer[i].erase(answer[i].begin() + j);
                    continue;
                }
                else
                    break;
            }
        }

        return answer;
    }
};