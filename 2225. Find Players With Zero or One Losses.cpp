class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {

        set<int> AnsZero, AnsOne;

        unordered_map<int, int> Lossers;

        for (int i = 0; i < matches.size(); i++)
        {
            Lossers[matches[i][1]]++;
        }

        for (int i = 0; i < matches.size(); i++)
        {
            // list of all players that have not lost any matches.
            if (Lossers.find(matches[i][0]) == Lossers.end())
                AnsZero.insert(matches[i][0]);

            // list of all players that have lost exactly one match.
            if (Lossers.find(matches[i][1]) != Lossers.end() && Lossers[matches[i][1]] == 1)
                AnsOne.insert(matches[i][1]);
        }

        vector<int> AnsZ;
        vector<int> AnsO;

        for (auto it = AnsZero.begin(); it != AnsZero.end(); it++)
        {
            AnsZ.push_back(*it);
        }

        for (auto it = AnsOne.begin(); it != AnsOne.end(); it++)
        {
            AnsO.push_back(*it);
        }

        return {AnsZ, AnsO};
    }
};