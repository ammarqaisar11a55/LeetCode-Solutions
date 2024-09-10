class Solution
{
public:
    bool isPathCrossing(string path)
    {

        unordered_set<string> Visited;

        int x = 0;
        int y = 0;

        string corridnates = to_string(x) + "," + to_string(y);
        Visited.insert(corridnates);

        for (int i = 0; i < path.length(); i++)
        {

            if (path[i] == 'N')
            {
                y++;
                x++;
            }
            else if (path[i] == 'S')
            {
                y--;
                x--;
            }
            else if (path[i] == 'E')
            {
                x++;
            }
            else if (path[i] == 'W')
            {
                x--;
            }

            string corridnates = to_string(x) + "," + to_string(y);
            if (Visited.find(corridnates) != Visited.end())
            {
                return true;
            }
            else
                Visited.insert(corridnates);
        }

        return false;
    }
};