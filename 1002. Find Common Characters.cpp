class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {

        vector<string> answer;

        for (int i = 0; i < words[0].length(); i++)
        {
            int count = 1;
            for (int j = 1; j < words.size(); j++)
            {
                if (words[j].find(words[0][i]) != string::npos)
                {
                    words[j].erase(words[j].begin() + words[j].find(words[0][i]));
                    count++;
                }
            }
            if (count == words.size())
            {
                string temp;
                temp.push_back(words[0][i]);
                answer.push_back(temp);
                temp.clear();
            }
        }
        return answer;
    }
};