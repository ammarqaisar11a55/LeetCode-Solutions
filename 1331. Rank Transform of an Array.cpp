class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {

        unordered_map<int, vector<int>> Mp;

        for (int i = 0; i < arr.size(); i++)
        {
            Mp[arr[i]].push_back(i);
        }

        sort(arr.begin(), arr.end());

        int rank = 1;
        vector<int> Ranks;
        Ranks.push_back(rank++);

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i - 1] == arr[i])
            {
                Ranks.push_back(Ranks.back());
            }
            else
            {
                Ranks.push_back(rank++);
            }
        }

        vector<int> Final_Ans(arr.size());

        for (int i = 0; i < arr.size(); i++)
        {
            int index = Mp[arr[i]].back();
            Mp[arr[i]].pop_back();
            Final_Ans[index] = Ranks[i];
        }

        return Final_Ans;
    }
};