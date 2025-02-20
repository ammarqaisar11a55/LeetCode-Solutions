class Solution
{
public:
    bool canSortArray(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size() - 1 - i; j++)
            {
                if (nums[j] > nums[j + 1])
                {
                    if (__builtin_popcount(nums[j]) == __builtin_popcount(nums[j + 1]))
                        swap(nums[j], nums[j + 1]);
                }
            }
        }

        return is_sorted(nums.begin(), nums.end());
    }
};

/*992/999 Passed: */

bool canSortArray(vector<int> nums)
{
    unordered_map<int, queue<int>> mp;

    for (int i : nums)
    {
        mp[__builtin_popcount(i)].push(i);
    }

    for (auto &group : mp)
    {
        vector<int> temp;
        while (!group.second.empty())
        {
            temp.push_back(group.second.front());
            group.second.pop();
        }

        sort(temp.begin(), temp.end());

        for (int num : temp)
        {
            group.second.push(num);
        }
    }

    int index = 0;
    vector<int> Sorted;

    for (int i = 0; i < nums.size(); i++)
    {
        int Bits = __popcount(nums[i]);

        Sorted.push_back(mp[Bits].front());
        mp[Bits].pop();
    }

    return is_sorted(Sorted.begin(), Sorted.end());
}