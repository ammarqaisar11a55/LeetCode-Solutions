class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        double average =
            accumulate(nums.begin(), nums.end(), 0.0, plus<double>());
        average = average / (double)nums.size();

        unordered_set<int> nums_values(nums.begin(), nums.end());

        for (int i = 1;; i++) {
            if (i > average && nums_values.find(i) == nums_values.end()) {
                return i;
            }
        }

        return -1;
    }
};
