class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string res;

        while (columnNumber > 0)
        {
            columnNumber--;
            char Character_to_Append = 'A' + (columnNumber % 26);
            res += Character_to_Append;
            columnNumber /= 26;
        }

        reverse(res.begin(), res.end());

        return res;
    }
};