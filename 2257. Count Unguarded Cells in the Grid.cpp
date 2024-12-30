class Solution
{
public:
    void DFS(int i, int j, vector<vector<int>> &Jail, char Direction_to_Visit)
    {
        if (i < 0 || j < 0 || i >= Jail.size() || j >= Jail[0].size() || Jail[i][j] == -1 || Jail[i][j] == 1)
            return;

        Jail[i][j] = 2;

        if (Direction_to_Visit == 'L')
        {
            DFS(i, j - 1, Jail, Direction_to_Visit);
        }

        if (Direction_to_Visit == 'R')
        {
            DFS(i, j + 1, Jail, Direction_to_Visit);
        }

        if (Direction_to_Visit == 'U')
        {
            DFS(i - 1, j, Jail, Direction_to_Visit);
        }

        if (Direction_to_Visit == 'D')
        {
            DFS(i + 1, j, Jail, Direction_to_Visit);
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {

        vector<vector<int>> Jail(m, vector<int>(n, 0));

        // 0: Ungaurded
        //  -1: Walls
        // 1: Gaurds

        for (auto g : guards)
        {
            Jail[g[0]][g[1]] = 1;
        }

        for (auto w : walls)
        {
            Jail[w[0]][w[1]] = -1;
        }

        for (auto g : guards)
        {
            int x = g[0];
            int y = g[1];
            DFS(x, y + 1, Jail, 'R');
            DFS(x, y - 1, Jail, 'L');
            DFS(x - 1, y, Jail, 'U');
            DFS(x + 1, y, Jail, 'D');
        }

        int res = 0;

        for (int i = 0; i < Jail.size(); i++)
            for (int j = 0; j < Jail[i].size(); j++)
                if (Jail[i][j] == 0)
                    res++;

        return res;
    }
};