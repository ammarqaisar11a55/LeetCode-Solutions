class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {

        unordered_set<int> ks;

        for (int i = 1; i <= k; i++)
        {
            ks.insert(i);
        }

        int countoperations = 0;

        for (int i = nums.size(); i >= 0; i--)
        {
            if (i < nums.size() && ks.find(nums[i]) != ks.end())
            {
                ks.erase(nums[i]);
            }

            if (ks.size() == 0)
                break;

            countoperations++;
        }

        return countoperations;
    }
};