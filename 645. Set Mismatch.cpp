class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {

        unordered_map<int, int> Mp;

        int duplicate = 0;
        int missing = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            Mp[nums[i]]++;
        }

        for (int i = 1; i <= nums.size(); i++)
        {
            // case 1 : duplicate:
            if (Mp[i] == 2)
            {
                duplicate = i;
            }

            // case 2 : missing:

            if (Mp[i] == 0)
            {
                missing = i;
            }
        }

        return {duplicate, missing};
    }
};