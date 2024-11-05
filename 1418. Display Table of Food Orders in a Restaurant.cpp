class Solution
{
public:
    vector<vector<string>> displayTable(vector<vector<string>> &orders)
    {

        set<string> fooditems;
        set<int> tableNo;
        unordered_map<string, unordered_map<string, int>> mp;

        for (vector<string> order : orders)
        {
            tableNo.insert(stoi(order[1]));
            fooditems.insert(order[2]);

            mp[order[1]][order[2]]++;
        }

        vector<string> firstRow = {"Table"};

        for (auto x : fooditems)
        {
            firstRow.push_back(x);
        }

        vector<vector<string>> Ans;
        Ans.push_back(firstRow);

        vector<int> tables(tableNo.begin(), tableNo.end());
        sort(tables.begin(), tables.end());
        reverse(tables.begin(), tables.end());

        for (int i = 0; i < tableNo.size(); i++)
        {
            vector<string> RowToInsert;
            string SingleTable = to_string(tables[tables.size() - 1]);
            tables.pop_back();

            RowToInsert.push_back(SingleTable);

            for (int j = 1; j < firstRow.size(); j++)
            {
                RowToInsert.push_back(to_string(mp[(SingleTable)][firstRow[j]]));
            }

            Ans.push_back(RowToInsert);
        }

        return Ans;
    }
};