class Solution
{
public:
    void Solve(vector<int> Current_Combination, vector<vector<int>> &Res, int k, int range, int start)
    {
        if (Current_Combination.size() == k)
        {
            if (Current_Combination.empty() == false)
            {
                Res.push_back(Current_Combination);
            }

            return;
        }

        for (int i = start; i <= range; i++)
        {
            Current_Combination.push_back(i);
            Solve(Current_Combination, Res, k, range, i + 1);
            Current_Combination.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> Res;
        Solve({}, Res, k, n, 1);
        return Res;
    }
};