class Solution
{
public:
    string convert(string s, int numRows)
    {

        if (numRows == 1)
            return s;

        int GoingDown = false;

        vector<string> Rows(numRows);
        int Current_Row = 0;

        for (int i = 0; i < s.length(); i++)
        {
            Rows[Current_Row].push_back(s[i]);

            if (Current_Row == Rows.size() - 1 || Current_Row == 0)
            {
                GoingDown = !GoingDown;
            }

            Current_Row += GoingDown == true ? 1 : -1;
        }

        string ans;

        for (string c : Rows)
        {
            ans += c;
        }

        return ans;
    }
};