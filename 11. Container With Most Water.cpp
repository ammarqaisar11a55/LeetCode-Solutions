class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int res = 0;

        int i = 0;
        int j = height.size() - 1;

        while (i < j)
        {
            int width = j - i;
            int current_min_height = min(height[i], height[j]);

            res = max(res, width * current_min_height);

            if (height[i] < height[j])
            {
                i++;
            }
            else
                j--;
        }

        return res;
    }
};