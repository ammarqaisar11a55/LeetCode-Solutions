class Solution
{
public:
    bool checkDistances(string s, vector<int> &distance)
    {

        unordered_map<char, int> Mp;

        for (int i = 0; i < s.length(); i++)
        {
            if (Mp.find(s[i]) == Mp.end())
            {
                Mp[s[i]] = i;
            }
            else
            {
                Mp[s[i]] = i - Mp[s[i]] - 1;
            }
        }

        for (auto x : Mp)
        {
            if (x.second != distance[x.first - 'a'])
                return false;
        }

        return true;
    }
};