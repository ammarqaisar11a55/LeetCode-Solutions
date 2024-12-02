class Solution
{
public:
    int maxDistance(vector<int> &colors)
    {

        int MaxDistance = INT_MIN;
        int i = 0;

        for (int j = 1; j < colors.size(); j++)
        {
            if (colors[j] != colors[0])
                MaxDistance = max(MaxDistance, abs(i - j));
        }

        reverse(colors.begin(), colors.end());

        for (int j = 1; j < colors.size(); j++)
        {
            if (colors[j] != colors[0])
                MaxDistance = max(MaxDistance, abs(i - j));
        }

        return MaxDistance;
    }
};