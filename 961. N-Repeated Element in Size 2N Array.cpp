class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[i] == nums[j])
                {
                    count++;
                }
            }
            if (count == nums.size() / 2)
            {
                return nums[i];
            }
        }
        return -1;
    }
};

class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {

        unordered_map<int, int> Freq;

        for (auto x : nums)
            Freq[x]++;

        for (auto x : Freq)
        {
            if (x.second == nums.size() / 2)
                return x.first;
        }

        return -1;
    }
};