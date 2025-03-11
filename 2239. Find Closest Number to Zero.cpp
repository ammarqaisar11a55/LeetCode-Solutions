class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
    int index_of_min_abs = -1;
    int min_abs = INT_MAX;

    sort(nums.begin(),nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        if (abs(nums[i]) <= min_abs)
        {
            index_of_min_abs = max(index_of_min_abs,i);
            min_abs = min(min_abs, abs(nums[i]));
        }
    }

    return nums[index_of_min_abs];
    }
};
