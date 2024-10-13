class Solution
{
public:
    int numSpecialEquivGroups(vector<string> &words)
    {

        unordered_set<string> Ans;

        for (string w : words)
        {
            string p;
            string q;

            for (int i = 0; i < w.length(); i++)
            {
                if (i & 1)
                {
                    p += w[i];
                }
                else
                {
                    q += w[i];
                }
            }

            sort(p.begin(), p.end());
            sort(q.begin(), q.end());

            p += q;

            Ans.insert(p);
        }

        return Ans.size();
    }
};