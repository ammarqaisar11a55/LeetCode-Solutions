class Solution
{
public:
    int countPoints(string rings)
    {

        unordered_map<int, unordered_set<char>> Rods;

        reverse(rings.begin(), rings.end());

        for (int i = 0; i < rings.size() - 1; i += 2)
        {
            Rods[rings[i] - '0'].insert(rings[i + 1]);
        }

        int count = 0;

        for (auto x : Rods)
        {
            if (x.second.size() == 3)
                count++;
        }

        return count;
    }
};