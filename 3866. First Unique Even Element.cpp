class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int i : nums) {
            if (i % 2 == 0)
                mp[i]++;
        }

        unordered_set<int> st;

        for (auto [x, y] : mp) {
            if (y == 1) {
                st.insert(x);
            }
        }

        for (int i : nums) {
            if (st.find(i) != st.end()) {
                return i;
            }
        }

        return -1;
    }
};