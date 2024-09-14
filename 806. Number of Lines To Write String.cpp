class Solution
{
public:
    vector<int> numberOfLines(vector<int> &widths, string s)
    {

        int lines = 1;
        int width = 0;

        for (int i = 0; i < s.length(); i++)
        {
            int w = widths[s[i] - 'a'];
            width += w;

            if (width > 100)
            {
                lines++;
                width = w;
            }
        }

        return {lines, width};
    }
};