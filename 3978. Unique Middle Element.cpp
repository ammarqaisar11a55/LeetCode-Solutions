class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int mid_index = (0 + nums.size()) / 2;

        for (int i = 0; i < nums.size(); i++) {
            if (i != mid_index && nums[i] == nums[mid_index]) {
                return false;
            }
        }

        return true;
    }
};