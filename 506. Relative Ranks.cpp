class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {

        unordered_map<int, int> Ids;
        vector<string> Final_Res(score.size(), "");

        for (int i = 0; i < score.size(); i++)
        {
            Ids[score[i]] = i;
        }

        sort(score.begin(), score.end());
        reverse(score.begin(), score.end());

        vector<string> res;

        for (int i = 0; i < score.size(); i++)
        {
            if (i == 0)
            {
                res.push_back("Gold Medal");
            }
            else if (i == 1)
            {
                res.push_back("Silver Medal");
            }
            else if (i == 2)
            {
                res.push_back("Bronze Medal");
            }
            else
                res.push_back(to_string(i + 1));
        }

        for (int i = 0; i < score.size(); i++)
        {
            int index = Ids[score[i]];
            Final_Res[index] = res[i];
        }

        return Final_Res;
    }
};