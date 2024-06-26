
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        unordered_set<int> N;

        sort(nums.rbegin(), nums.rend());

        int j = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (N.find(nums[i]) == N.end())
            {
                j++;
                if (j == k)
                {
                    return nums[i];
                }
            }
            else
                N.insert(nums[i]);
        }

        return -1;
    }
};
