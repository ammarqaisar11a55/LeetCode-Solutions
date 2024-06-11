class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {

        vector<int> expected = heights;
        sort(expected.begin(), expected.end());
        int not_matched = 0;

        for (int i = 0; i < heights.size(); i++)
        {
            if (heights[i] != expected[i])
            {
                not_matched++;
            }
        }

        return not_matched;
    }
};