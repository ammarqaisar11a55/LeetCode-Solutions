class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int res = 0;

        int left = 0, right = nums.size() - 1;

        while (left < right) {
            if (nums[right] == 0) {
                right--;
                continue;
            }

            if (nums[left] != 0) {
                left++;
                continue;
            }

            res++;
            left++;
            right--;
        }

        return res;
    }
};