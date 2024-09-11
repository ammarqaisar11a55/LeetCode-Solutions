class Solution
{
public:
    vector<int> occurrencesOfElement(vector<int> &nums, vector<int> &queries, int x)
    {

        unordered_map<int, vector<int>> Mp;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == x)
                Mp[x].push_back(i);
        }

        vector<int> Ans;

        for (int i = 0; i < queries.size(); i++)
        {
            if (Mp.find(x) == Mp.end() || queries[i] > Mp[x].size())
            {
                Ans.push_back(-1);
            }
            else
            {
                vector<int> P = Mp[x];
                Ans.push_back(P[queries[i] - 1]);
            }
        }

        return Ans;
    }
};

class Solution
{
public:
    vector<int> occurrencesOfElement(vector<int> &nums, vector<int> &queries, int x)
    {

        vector<int> P;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == x)
                P.push_back(i);
        }

        vector<int> Ans;

        for (int i = 0; i < queries.size(); i++)
        {
            if (P.size() == 0 || queries[i] > P.size())
            {
                Ans.push_back(-1);
            }
            else
            {
                Ans.push_back(P[queries[i] - 1]);
            }
        }

        return Ans;
    }
};