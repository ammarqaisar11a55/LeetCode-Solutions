class Solution
{
public:
    string frequencySort(string s)
    {

        unordered_map<char, int> Mp;

        for (int i = 0; i < s.length(); i++)
            Mp[s[i]]++;

        sort(s.begin(), s.end(), [&Mp](char a, char b)
             {
                 if (Mp[a] == Mp[b])
                 {
                     return a < b;
                 }

                 return Mp[a] > Mp[b];
             });

        return s;
    }
};