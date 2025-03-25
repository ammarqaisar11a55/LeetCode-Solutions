class Solution {
public:
    void Solve(int current_sum, int target_sum, int index, vector<int>& nums,
               int& res) {
        if (index >= nums.size()) {
            if (current_sum == target_sum) {
                res++;
            }
            return;
        }

        Solve(current_sum - nums[index], target_sum, index + 1, nums, res);
        Solve(current_sum + nums[index], target_sum, index + 1, nums, res);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int res = 0;
        Solve(0, target, 0, nums, res);
        return res;
    }
};
