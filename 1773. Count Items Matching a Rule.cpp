class Solution
{
public:
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
    {

        int ColumnToBeChecked;

        if (ruleKey == "type")
        {
            ColumnToBeChecked = 0;
        }
        else if (ruleKey == "color")
        {
            ColumnToBeChecked = 1;
        }
        else
            ColumnToBeChecked = 2;

        int count = 0;

        for (int i = 0; i < items.size(); i++)
        {
            if (items[i][ColumnToBeChecked] == ruleValue)
            {
                count++;
            }
        }
        return count;
    }
};