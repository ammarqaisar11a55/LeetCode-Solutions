class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {
        vector<int> Res;
        unordered_map<int, int> Balls_with_Color;
        unordered_set<int> Distinct_Colors;
        unordered_map<int, int> Colors_Freq;

        for (vector<int> Que : queries)
        {
            int Ball = Que[0];
            int Color = Que[1];

            if (Balls_with_Color.find(Ball) != Balls_with_Color.end())
            {
                int its_old_color = Balls_with_Color[Ball];
                Colors_Freq[its_old_color]--;

                if (Colors_Freq[its_old_color] == 0)
                {
                    Distinct_Colors.erase(its_old_color);
                }
            }

            Colors_Freq[Color]++;
            Balls_with_Color[Ball] = Color;
            Distinct_Colors.insert(Color);

            Res.push_back((int)Distinct_Colors.size());
        }

        return Res;
    }
};