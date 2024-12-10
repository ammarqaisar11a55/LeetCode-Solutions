class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {

        queue<pair<int, int>> Rotten_Oranges_Coordinates;
        int Count_Fresh_Oranges = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    Rotten_Oranges_Coordinates.push({i, j});
                }
                else if (grid[i][j] == 1)
                    Count_Fresh_Oranges++;
            }
        }

        if (Count_Fresh_Oranges == 0)
            return 0;

        int Mins = 0;
        vector<vector<int>> Directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        while (!Rotten_Oranges_Coordinates.empty())
        {
            int size = Rotten_Oranges_Coordinates.size();
            bool HasRotten_on_Current_Iteration = false;

            for (int i = 0; i < size; i++)
            {
                int X = Rotten_Oranges_Coordinates.front().first;
                int Y = Rotten_Oranges_Coordinates.front().second;
                Rotten_Oranges_Coordinates.pop();

                for (vector<int> Dir : Directions)
                {
                    int New_X = X + Dir[0];
                    int New_Y = Y + Dir[1];

                    if (New_X >= 0 && New_Y >= 0 && New_X < grid.size() && New_Y < grid[0].size() && grid[New_X][New_Y] == 1)
                    {
                        grid[New_X][New_Y] = 2;
                        Rotten_Oranges_Coordinates.push({New_X, New_Y});
                        HasRotten_on_Current_Iteration = true;
                        Count_Fresh_Oranges--;
                    }
                }
            }
            Mins += HasRotten_on_Current_Iteration == true ? 1 : 0;
        }

        return Count_Fresh_Oranges == 0 ? Mins : -1;
    }
};