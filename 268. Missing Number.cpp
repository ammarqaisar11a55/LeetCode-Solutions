class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        for (int i = 0; i <= nums.size(); i++) {
            if (st.find(i) == st.end())
                return i;
        }

        return 0;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();
        int total = n * (n + 1) / 2;

        int sum = accumulate(nums.begin(), nums.end(), 0);

        return total - sum;
    }
};
