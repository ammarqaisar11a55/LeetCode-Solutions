class Solution
{
public:
    string evaluate(string s, vector<vector<string>> &knowledge)
    {

        unordered_map<string, string> mp;

        for (vector<string> T : knowledge)
        {
            mp[T[0]] = T[1];
        }

        string ans;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                i++;
                string bracketdata;

                while (s[i] != ')')
                {
                    bracketdata.push_back(s[i]);
                    i++;
                }

                if (mp.find(bracketdata) == mp.end())
                {
                    bracketdata = "?";
                }
                else
                {
                    bracketdata = mp[bracketdata];
                }

                ans += bracketdata;
            }
            else
            {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};