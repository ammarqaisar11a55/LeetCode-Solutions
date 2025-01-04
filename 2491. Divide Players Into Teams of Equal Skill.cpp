class Solution
{
public:
    long long dividePlayers(vector<int> &skill)
    {
        long long res = 0;
        int Previous_Pair_Sum = -1;
        sort(skill.begin(), skill.end());

        int start = 0;
        int end = skill.size() - 1;

        while (start < end)
        {
            int Current_Pair_Sum = skill[start] + skill[end];
            int Current_Pair_Product = skill[start] * skill[end];

            if (Previous_Pair_Sum == -1)
            {
                Previous_Pair_Sum = Current_Pair_Sum;
                res = Current_Pair_Product;
            }
            else
            {
                if (Current_Pair_Sum != Previous_Pair_Sum)
                    return -1;

                res += Current_Pair_Product;
            }

            start++;
            end--;
        }

        return res;
    }
};