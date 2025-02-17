class Solution
{
public:
    void Solve(string current_string, unordered_set<string> &Sequences_Count, unordered_set<int> &Used_Positions, string &tiles)
    {
        if (current_string.empty() == false)
        {
            Sequences_Count.insert(current_string);
        }

        for (int i = 0; i < tiles.length(); i++)
        {
            if (Used_Positions.find(i) == Used_Positions.end())
            {
                Used_Positions.insert(i);
                Solve(current_string + tiles[i], Sequences_Count, Used_Positions, tiles);
                Used_Positions.erase(i);
            }
        }
    }

    int numTilePossibilities(string tiles)
    {

        unordered_set<string> res;
        unordered_set<int> Used;
        Solve("", res, Used, tiles);

        return res.size();
    }
};