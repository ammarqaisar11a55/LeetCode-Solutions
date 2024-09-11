class Solution
{
public:
    int findChampion(vector<vector<int>> &grid)
    {

        int Row = -1;
        int Max_Ones = INT_MIN;

        for (int i = 0; i < grid.size(); i++)
        {
            int countOnes = 0;
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                    countOnes++;
            }
            if (countOnes > Max_Ones)
            {
                Max_Ones = countOnes;
                Row = i;
            }
        }

        return Row;
    }
};