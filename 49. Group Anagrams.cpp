class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        unordered_map<string, vector<string>> Groups;

        for (int i = 0; i < strs.size(); i++)
        {
            string key = strs[i];
            sort(key.begin(), key.end());

            Groups[key].push_back(strs[i]);
        }

        vector<vector<string>> Ans;

        for (auto x : Groups)
        {

            Ans.push_back(x.second);
        }

        return Ans;
    }
};