class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {

        int MaxRows = 0;

        unordered_map<int, int> Mp;

        for (int i : nums)
        {
            Mp[i]++;
            MaxRows = max(MaxRows, Mp[i]);
        }

        vector<unordered_set<int>> UniqueRows(MaxRows);

        int CurrentRow = 0;

        while (Mp.empty() == false)
        {
            int element = (Mp.begin())->first;

            Mp[element]--;

            if (Mp[element] <= 0)
            {
                Mp.erase(element);
            }

            if (UniqueRows[CurrentRow].find(element) == UniqueRows[CurrentRow].end())
            {
                UniqueRows[CurrentRow].insert(element);
            }
            else
            {
                while (true)
                {
                    if (UniqueRows[CurrentRow].find(element) == UniqueRows[CurrentRow].end())
                    {
                        UniqueRows[CurrentRow].insert(element);
                        break;
                    }

                    CurrentRow = (CurrentRow + 1) % MaxRows;
                }
            }
        }

        vector<vector<int>> Ans;

        for (int i = 0; i < UniqueRows.size(); i++)
        {
            vector<int> Row = vector<int>{UniqueRows[i].begin(), UniqueRows[i].end()};
            Ans.push_back(Row);
        }

        return Ans;
    }
};