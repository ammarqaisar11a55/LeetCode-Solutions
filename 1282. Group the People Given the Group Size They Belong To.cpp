class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {

        unordered_map<int, vector<int>> Groups;
        vector<vector<int>> Ans;

        for (int i = 0; i < groupSizes.size(); i++)
        {
            Groups[groupSizes[i]].push_back(i);

            if (Groups[groupSizes[i]].size() == groupSizes[i])
            {
                Ans.push_back(Groups[groupSizes[i]]);
                Groups[groupSizes[i]].clear();
            }
        }

        return Ans;
    }
};