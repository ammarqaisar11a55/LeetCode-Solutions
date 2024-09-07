class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {

        // Adding Common Strings only

        unordered_map<string, vector<int>> Mp;

        for (int i = 0; i < list1.size(); i++)
            Mp[list1[i]].push_back(i);

        for (int i = 0; i < list2.size(); i++)
        {
            if (Mp.find(list2[i]) != Mp.end())
            {
                Mp[list2[i]].push_back(i);
            }
        }

        // Removing Strings with Single Frequency:

        vector<string> ToBeRemoved;

        for (auto x : Mp)
        {
            if (x.second.size() < 2)
                ToBeRemoved.push_back(x.first);
        }

        for (int i = 0; i < ToBeRemoved.size(); i++)
        {
            Mp.erase(ToBeRemoved[i]);
        }

        int min_sum = INT_MAX;

        for (auto x : Mp)
        {
            int sum = x.second[0] + x.second[1];
            min_sum = min(min_sum, sum);
        }

        vector<string> Ans;

        for (auto x : Mp)
        {
            if (x.second[0] + x.second[1] == min_sum)
            {
                Ans.push_back(x.first);
            }
        }

        return Ans;
    }
};