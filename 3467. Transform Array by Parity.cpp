class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int odds = 0;
        int evens = 0;

        for (int i : nums)
            if (i & 1) {
                odds++;
            } else
                evens++;

        for (int i = 0; i < nums.size(); i++) {
            if (evens > 0) {
                nums[i] = 0;
                evens--;
            } else {
                nums[i] = 1;
            }
        }

        return nums;
    }
};
