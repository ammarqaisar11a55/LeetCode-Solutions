class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string s)
    {

        vector<vector<int>> Ans;

        stack<pair<char, int>> S;
        S.push({s[0], 0});

        for (int i = 1; i < s.length(); i++)
        {
            if (S.top().first == s[i])
            {
                S.push({s[i], i});
            }
            else
            {
                if (S.size() < 3)
                {
                    while (!S.empty())
                    {
                        S.pop();
                    }

                    S.push({s[i], i});
                    continue;
                }

                int end = S.top().second;
                int start = INT_MAX;

                while (!S.empty())
                {
                    pair<int, int> Temp = S.top();
                    start = min(start, Temp.second);
                    S.pop();
                }

                Ans.push_back({start, end});
                S.push({s[i], i});
            }
        }

        if (!S.empty() && S.size() >= 3)
        {
            int end = S.top().second;
            int start = INT_MAX;

            while (!S.empty())
            {
                pair<int, int> Temp = S.top();
                start = min(start, Temp.second);
                S.pop();
            }

            Ans.push_back({start, end});
        }

        return Ans;
    }
};