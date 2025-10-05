class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i & 1) {
                res -= nums[i];
            } else {
                res += nums[i];
            }
        }

        return res;
    }
};
