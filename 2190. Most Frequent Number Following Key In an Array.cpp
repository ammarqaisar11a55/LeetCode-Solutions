class Solution
{
public:
    int mostFrequent(vector<int> &nums, int key)
    {

        unordered_map<int, int> Mp;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == key)
                Mp[nums[i + 1]]++;
        }

        int Number;
        int MAXI = -1;

        for (auto x : Mp)
        {
            if (x.second > MAXI)
            {
                MAXI = x.second;
                Number = x.first;
            }
        }

        return Number;
    }
};