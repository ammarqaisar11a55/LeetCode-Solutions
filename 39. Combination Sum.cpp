class Solution
{
public:
    void Solve(vector<int> &Candidates, vector<int> Current_Combination, int current_sum, int &target, vector<vector<int>> &Res, int Current_Index)
    {
        if (current_sum >= target)
        {
            if (current_sum == target)
                Res.push_back(Current_Combination);
            return;
        }

        for (int i = Current_Index; i < Candidates.size(); i++)
        {
            Current_Combination.push_back(Candidates[i]);
            Solve(Candidates, Current_Combination, current_sum + Candidates[i], target, Res, i);
            Current_Combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> Res;
        Solve(candidates, {}, 0, target, Res, 0);
        return Res;
    }
};