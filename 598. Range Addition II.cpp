class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int>> &ops)
    {

        int rc = m;
        int col = n;

        for (int i = 0; i < ops.size(); i++)
        {
            int row = ops[i][0];
            int cols = ops[i][1];

            rc = min(rc, row);
            col = min(col, cols);
        }

        return rc * col;
    }
};