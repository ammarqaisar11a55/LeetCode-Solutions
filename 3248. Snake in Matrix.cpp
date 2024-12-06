class Solution
{
public:
    int finalPositionOfSnake(int n, vector<string> &commands)
    {

        vector<vector<int>> Grid(n, vector<int>(n));
        int count = 0;

        for (auto &x : Grid)
            for (auto &y : x)
                y = count++;

        int CurrentRow = 0;
        int CurrentCol = 0;

        for (int i = 0; i < commands.size(); i++)
        {
            if (commands[i] == "LEFT")
                CurrentCol--;

            if (commands[i] == "RIGHT")
                CurrentCol++;

            if (commands[i] == "UP")
                CurrentRow--;

            if (commands[i] == "DOWN")
                CurrentRow++;
        }

        return Grid[CurrentRow][CurrentCol];
    }
    
};