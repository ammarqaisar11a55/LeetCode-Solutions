class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int res = INT_MAX;

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        for (auto [element, positions] : mp) {
            if (positions.size() >= 3) {
                for (int i = 2; i < positions.size(); i++) {
                    int dis = abs(positions[i] - positions[i - 1]) +
                              abs(positions[i] - positions[i - 2]) +
                              abs(positions[i - 1] - positions[i - 2]);
                    res = min(res, dis);
                }
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};
