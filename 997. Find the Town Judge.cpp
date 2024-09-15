class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {

        unordered_set<int> ThoseWhoTrust;
        unordered_map<int, int> OnWhomPeopleTrust;

        for (int i = 0; i < trust.size(); i++)
        {
            ThoseWhoTrust.insert(trust[i][0]);
            OnWhomPeopleTrust[trust[i][1]]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (OnWhomPeopleTrust[i] == n - 1 && ThoseWhoTrust.find(i) == ThoseWhoTrust.end())
                return i;
        }

        return -1;
    }
};