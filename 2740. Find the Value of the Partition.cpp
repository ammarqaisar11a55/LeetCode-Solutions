class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int res = INT_MAX;

        for (int i = 0; i < nums.size() - 1; i++) {
            res = min(res, abs(nums[i] - nums[i + 1]));
        }

        return res;
    }
};
