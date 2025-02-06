
class Solution
{
public:
    void Solve(int k, vector<int> Current_Combination, int current_sum, int &target, vector<vector<int>> &Res, int Current_Index, unordered_set<int> &Used_Numbers)
    {
        if (k == 0)
        {
            if (current_sum == target)
            {
                Res.push_back(Current_Combination);
            }

            return;
        }

        for (int i = Current_Index; i <= 9; i++)
        {
            if (Used_Numbers.find(i) == Used_Numbers.end())
            {
                Current_Combination.push_back(i);
                Used_Numbers.insert(i);
                Solve(k - 1, Current_Combination, current_sum + i, target, Res, i + 1, Used_Numbers);
                Current_Combination.pop_back();
                Used_Numbers.erase(i);
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> Res;
        unordered_set<int> Used_Numbers;
        Solve(k, {}, 0, n, Res, 1, Used_Numbers);
        return Res;
    }
};