class Solution
{
public:
    bool Solve(vector<int> &Res, int index, int n, unordered_set<int> &Corretly_Placed_No)
    {
        // Skip already placed numbers
        while (index < Res.size() && Res[index] != 0)
            index++;

        if (index >= Res.size())
            return true;

        for (int i = n; i >= 1; i--)
        {
            if (Corretly_Placed_No.find(i) != Corretly_Placed_No.end())
                continue;

            if (i == 1)
            {
                if (Res[index] == 0)
                {
                    Res[index] = 1;
                    Corretly_Placed_No.insert(1);

                    if (Solve(Res, index + 1, n, Corretly_Placed_No))
                        return true;

                    Res[index] = 0;
                    Corretly_Placed_No.erase(1);
                }
            }
            else if (Res[index] == 0 && index + i < Res.size() && Res[index + i] == 0)
            {
                Res[index] = i;
                Res[index + i] = i;
                Corretly_Placed_No.insert(i);

                if (Solve(Res, index + 1, n, Corretly_Placed_No))
                    return true;

                // 🔥 Backtrack
                Res[index] = 0;
                Res[index + i] = 0;
                Corretly_Placed_No.erase(i);
            }
        }

        return false;
    }

    vector<int> constructDistancedSequence(int n)
    {
        if (n == 1)
            return {1};

        vector<int> Res(n * 2 - 1, 0);
        unordered_set<int> Corretly_Placed_No;
        Solve(Res, 0, n, Corretly_Placed_No);

        return Res;
    }
};