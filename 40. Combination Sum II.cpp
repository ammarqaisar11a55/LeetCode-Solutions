class Solution
{
public:
    void Solve(vector<int> &Candidates, vector<int> Current_Combination, int current_sum, int &target, vector<vector<int>> &Res, int Current_Index)
    {
        if (current_sum >= target)
        {
            if (current_sum == target)
            {
                Res.push_back(Current_Combination);
            }

            return;
        }

        unordered_set<int> st;

        for (int i = Current_Index; i < Candidates.size(); i++)
        {
            if (st.find(Candidates[i]) == st.end())
            {
                Current_Combination.push_back(Candidates[i]);
                Solve(Candidates, Current_Combination, current_sum + Candidates[i], target, Res, i + 1);
                Current_Combination.pop_back();
                st.insert(Candidates[i]);
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> Res;
        sort(candidates.begin(), candidates.end());
        Solve(candidates, {}, 0, target, Res, 0);
        return Res;
    }
};