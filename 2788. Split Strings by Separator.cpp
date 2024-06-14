class Solution
{
public:
    vector<string> splitWordsBySeparator(vector<string> &words, char separator)
    {

        vector<string> answer;

        for (int i = 0; i < words.size(); i++)
        {
            string temp;
            words[i].push_back(separator);
            for (int j = 0; j < words[i].length(); j++)
            {
                if (words[i][j] != separator)
                {
                    temp.push_back(words[i][j]);
                }
                else
                {
                    if (!temp.empty())
                        answer.push_back(temp);
                    temp.clear();
                }
            }
        }
        return answer;
    }
};