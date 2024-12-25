class Solution
{
public:
    bool canMakeSquare(vector<vector<char>> &grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (i + 1 < grid.size() && j + 1 < grid[i].size())
                {
                    int Count_Black = 0, Count_White = 0;

                    if (grid[i][j] == 'B')
                    {
                        Count_Black++;
                    }
                    else
                        Count_White++;

                    if (grid[i][j + 1] == 'B')
                    {
                        Count_Black++;
                    }
                    else
                        Count_White++;

                    if (grid[i + 1][j] == 'B')
                    {
                        Count_Black++;
                    }
                    else
                        Count_White++;

                    if (grid[i + 1][j + 1] == 'B')
                    {
                        Count_Black++;
                    }
                    else
                        Count_White++;

                    if (Count_Black == 3 || Count_White == 3 || Count_Black == 4 || Count_White == 4)
                        return true;
                }
            }
        }

        return false;
    }
};