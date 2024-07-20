class Solution
{
public:
    vector<int> distinctDifferenceArray(vector<int> &nums)
    {

        unordered_set<int> Prefixes;
        unordered_set<int> Suffixes;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            // Prefixes:
            for (int j = i; j >= 0; j--)
                Prefixes.insert(nums[j]);

            // Suffixes:

            for (int k = i + 1; k < nums.size(); k++)
                Suffixes.insert(nums[k]);

            ans.push_back(Prefixes.size() - Suffixes.size());

            Prefixes.clear();
            Suffixes.clear();
        }

        return ans;
    }
};