class Solution
{
public:
    int maxOperations(vector<int> &nums)
    {

        if (nums.size() < 2)
            return 0;

        if (nums.size() == 2)
            return 1;

        int previous_sum = nums[0] + nums[1];

        int CountOperations = 1;

        for (int i = 2; i < nums.size(); i += 2)
        {
            if (i < nums.size() && i + 1 < nums.size() && (nums[i] + nums[i + 1]) == previous_sum)
            {
                CountOperations++;
            }
            else
            {
                break;
            }
        }
        return CountOperations;
    }
};