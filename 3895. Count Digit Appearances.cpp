class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];

            while (num > 0) {
                int d = num % 10;

                if (d == digit) {
                    res++;
                }

                num /= 10;
            }
        }

        return res;
    }
};