class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int res = k;

        unordered_set<int> st(nums.begin(), nums.end());

        int right = 1;

        while (true) {
            if (st.find(k * right) == st.end()) {
                res = k * right;
                break;
            } else {
                right++;
            }
        }

        return res;
    }
};
