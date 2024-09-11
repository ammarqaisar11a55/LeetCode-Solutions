class Solution
{
public:
    string largestWordCount(vector<string> &messages, vector<string> &senders)
    {

        unordered_map<string, int> Mp;
        int Maxi = INT_MIN;

        for (int i = 0; i < senders.size(); i++)
        {
            int NWords = count(messages[i].begin(), messages[i].end(), ' ') + 1;
            Mp[senders[i]] += NWords;

            Maxi = max(Maxi, Mp[senders[i]]);
        }

        string Ans = "";

        for (auto x : Mp)
        {
            if (x.second == Maxi)
            {
                Ans = max(Ans, x.first);
            }
        }

        return Ans;
    }
};