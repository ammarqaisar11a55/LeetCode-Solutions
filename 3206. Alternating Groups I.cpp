class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors)
    {

        int res = 0;

        for (int i = 0; i < colors.size(); i++)
        {
            if (colors[i] != colors[(i + 1) % colors.size()] && colors[(i + 1) % colors.size()] != colors[(i + 2) % colors.size()])
                res++;
        }

        return res;
    }
};