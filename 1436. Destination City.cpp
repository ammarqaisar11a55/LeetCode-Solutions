class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {

        unordered_set<string> Outgoings;

        for (int i = 0; i < paths.size(); i++)
        {
            Outgoings.insert(paths[i][0]);
        }

        for (int i = 0; i < paths.size(); i++)
        {
            if (Outgoings.find(paths[i][1]) == Outgoings.end())
                return paths[i][1];
        }

        return "";
    }
};