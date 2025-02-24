class Solution
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        int Prev_One = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                if (Prev_One == -1)
                {
                    Prev_One = i;
                }
                else
                {
                    if (i - Prev_One - 1 < k)
                    {
                        return false;
                    }
                    else
                    {
                        Prev_One = i;
                    }
                }
            }
        }

        return true;
    }
};