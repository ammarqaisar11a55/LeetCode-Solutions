class Solution
{
public:
    string oddString(vector<string> &words)
    {

        map<vector<int>, pair<int, int>> Mp;

        for (int i = 0; i < words.size(); i++)
        {
            vector<int> Temp;
            string s = words[i];

            for (int j = 0; j < words[i].length() - 1; j++)
            {
                int c = s[j + 1] - s[j];

                Temp.push_back(c);
            }

            Mp[Temp].first = i;
            Mp[Temp].second++;
        }

        int ans = -1;

        for (auto X : Mp)
        {
            if (X.second.second == 1)
                ans = X.second.first;
        }

        return words[ans];
    }
};