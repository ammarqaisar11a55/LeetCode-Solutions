class Solution
{
public:
    vector<string> stringMatching(vector<string> &words)
    {

        vector<string> ans;

        sort(words.begin(), words.end());

        for (int i = 0; i < words.size(); i++)
        {
            for (int j = words.size() - 1; j >= 0; j--)
            {
                if (words[j].find(words[i]) != string::npos && i != j)
                {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};