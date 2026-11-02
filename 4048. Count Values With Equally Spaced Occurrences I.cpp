class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {

        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        unordered_set<int> st;

        for (auto i : mp) {
            if (i.second == 3) {
                st.insert(i.first);
            }
        }

        int res = 0;

        unordered_map<int, vector<int>> positions;

        for (int i = 0; i < nums.size(); i++) {
            if (st.find(nums[i]) != st.end()) {
                positions[nums[i]].push_back(i);
            }
        }

        for (auto x : positions) {
            if (x.second[1] - x.second[0] == x.second[2] - x.second[1]) {
                res++;
            }
        }

        return res;
    }
};