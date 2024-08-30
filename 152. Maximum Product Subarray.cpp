class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {

        int result = nums[0];
        int MaxP = nums[0];
        int MinP = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                swap(MaxP, MinP);

            MaxP = max(MaxP * nums[i], nums[i]);
            MinP = min(MinP * nums[i], nums[i]);

            result = max(result, MaxP);
        }

        return result;
    }
};