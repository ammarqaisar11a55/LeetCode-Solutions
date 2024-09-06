class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {

        unordered_map<char, int> Mp;

        for (string word : words)
        {
            for (char w : word)
            {
                Mp[w]++;
            }
        }

        for (auto x : Mp)
        {
            if (x.second % words.size() != 0)
                return false;
        }

        return true;
    }
};