class Solution
{
public:
    bool isArraySpecial(vector<int> &nums)
    {

        if (nums.size() == 1)
        {
            return true;
        }

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (ParityCheck(nums[i]) == ParityCheck(nums[i + 1]))
            {
                return false;
            }
        }

        return true;
    }

    bool ParityCheck(int x)
    {
        return x % 2 == 0;
    }
};