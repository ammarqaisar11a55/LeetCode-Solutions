class Solution
{
public:
    vector<string> divideString(string s, int k, char fill)
    {

        string single;
        vector<string> Ans;

        for (int i = 0; i < s.length(); i++)
        {
            single.push_back(s[i]);

            if (single.length() == k)
            {
                Ans.push_back(single);
                single.clear();
            }
        }

        if (!single.empty() && single.length() == k)
        {
            Ans.push_back(single);
            single.clear();
        }
        else if (!single.empty() && single.size() < k)
        {
            while (single.size() < k)
                single.push_back(fill);

            Ans.push_back(single);
        }

        return Ans;
    }
};