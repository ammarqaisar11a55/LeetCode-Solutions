class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {

        int current_size = nums.size();

        for (int i = 0; i < current_size; i++) {
            nums.push_back(nums[current_size - 1 - i]);
        }

        return nums;
    }
};