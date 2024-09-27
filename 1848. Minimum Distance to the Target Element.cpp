class Solution
{
public:
    int getMinDistance(vector<int> &nums, int target, int start)
    {

        int Ans = INT_MAX;
        vector<int> Ps;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                Ps.push_back(i);
            }
        }

        for (int i = 0; i < Ps.size(); i++)
        {
            Ans = min(Ans, abs(Ps[i] - start));
        }

        return Ans;
    }
};