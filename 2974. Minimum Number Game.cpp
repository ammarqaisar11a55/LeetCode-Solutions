class Solution
{
public:
    vector<int> numberGame(vector<int> &nums)
    {

        vector<int> Alice;
        vector<int> Bob;
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i = i + 2)
        {
            Alice.push_back(nums[i - 1]);
            Bob.push_back(nums[i]);
        }

        nums.clear();

        for (int i = 0; i < Alice.size() || i < Bob.size(); i++)
        {
            if (i < Bob.size())
                nums.push_back(Bob[i]);

            if (i < Alice.size())
                nums.push_back(Alice[i]);
        }

        return nums;
    }
};