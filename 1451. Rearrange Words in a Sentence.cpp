class Solution
{
public:
    string arrangeWords(string text)
    {

        text[0] = towlower(text[0]);

        vector<pair<string, int>> Words;
        int word_position = 0;
        string single;
        text.push_back(' ');

        for (int i = 0; i < text.length(); i++)
        {
            if (text[i] == ' ')
            {
                if (!single.empty())
                {
                    Words.push_back({single, word_position});
                    word_position++;
                    single.clear();
                }
            }
            else
            {
                single.push_back(text[i]);
            }
        }

        sort(Words.begin(), Words.end(), [](pair<string, int> a, pair<string, int> b)
             {

        if(a.first.length()==b.first.length())
            return a.second < b.second;

        return a.first.length() < b.first.length(); });

        string ans;

        for (int i = 0; i < Words.size(); i++)
        {
            ans += Words[i].first + " ";
        }

        ans[0] = toupper(ans[0]);

        if (!ans.empty() && ans[ans.length() - 1] == ' ')
            ans.pop_back();

        return ans;
    }
};