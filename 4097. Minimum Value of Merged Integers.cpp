class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int res = INT_MAX;

        for (int i = 0; i < nums.size(); i += 2) {
            string first = to_string(nums[i]);
            string second = to_string(nums[i + 1]);

            res = min(res, stoi(first + second));
        }

        return res;
    }
};