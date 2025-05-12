class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());

        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> res;
        int current_sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (res.empty()) {
                total_sum -= nums[i];
                current_sum += nums[i];
                res.push_back(nums[i]);
            } else if (current_sum <= total_sum) {
                current_sum += nums[i];
                total_sum -= nums[i];
                res.push_back(nums[i]);
            } else
                break;
        }

        return res;
    }
};
