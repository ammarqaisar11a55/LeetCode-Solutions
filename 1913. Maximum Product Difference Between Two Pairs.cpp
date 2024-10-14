class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {

        int Max1 = INT_MIN;
        int Max2 = INT_MIN;

        int Min1 = INT_MAX;
        int Min2 = INT_MAX;

        for (auto x : nums)
        {
            if (x > Max1)
            {
                Max2 = Max1;
                Max1 = x;
            }
            else if (x > Max2)
            {
                Max2 = x;
            }

            if (x < Min1)
            {
                Min2 = Min1;
                Min1 = x;
            }
            else if (x < Min2)
            {
                Min2 = x;
            }
        }

        return (Max1 * Max2) - (Min1 * Min2);
    }
};