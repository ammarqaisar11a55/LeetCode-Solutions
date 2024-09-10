class Solution
{
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2)
    {

        map<int, int> Accumulation;

        for (int i = 0; i < items1.size(); i++)
        {
            Accumulation[items1[i][0]] = items1[i][1];
        }

        for (int i = 0; i < items2.size(); i++)
        {
            if (Accumulation.find(items2[i][0]) != Accumulation.end())
            {
                Accumulation[items2[i][0]] += items2[i][1];
            }
            else
            {
                Accumulation[items2[i][0]] = items2[i][1];
            }
        }

        vector<vector<int>> Ans;

        for (auto x : Accumulation)
        {
            Ans.push_back({x.first, x.second});
        }

        return Ans;
    }
};