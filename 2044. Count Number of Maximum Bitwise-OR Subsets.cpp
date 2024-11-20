class Solution
{
public:
    void Subsets(int index, vector<int> SingleSubSet, vector<vector<int>> &FinalSets, vector<int> &Nums)
    {
        if (index >= Nums.size())
        {
            FinalSets.push_back(SingleSubSet);
            return;
        }

        Subsets(index + 1, SingleSubSet, FinalSets, Nums);

        SingleSubSet.push_back(Nums[index]);
        Subsets(index + 1, SingleSubSet, FinalSets, Nums);
    }

    int countMaxOrSubsets(vector<int> &nums)
    {

        vector<vector<int>> FinalSubsets;
        vector<int> SingleSubset;
        Subsets(0, SingleSubset, FinalSubsets, nums);

        unordered_map<int, int> Mp;
        int MaxOR = INT_MIN;
        int MaxCount = 0;

        for (int i = 0; i < FinalSubsets.size(); i++)
        {
            int OR = 0;
            for (int j = 0; j < FinalSubsets[i].size(); j++)
            {
                OR |= FinalSubsets[i][j];
            }
            MaxOR = max(MaxOR, OR);
            Mp[OR]++;
        }

        return Mp[MaxOR];
    }
};