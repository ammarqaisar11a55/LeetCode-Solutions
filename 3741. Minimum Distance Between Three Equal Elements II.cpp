class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int res = INT_MAX;
        unordered_map<int, vector<int>> pos;

        for (int i = 0; i < nums.size(); i++) {
            pos[nums[i]].push_back(i);
        }

        for (auto [num, pos] : pos) {
            if (pos.size() >= 3) {

                for (int i = 2; i < pos.size(); i++) {
                    int dis = abs(pos[i - 2] - pos[i - 1]) +
                              abs(pos[i - 2] - pos[i]) +
                              abs(pos[i - 1] - pos[i]);
                    res = min(res, dis);
                }
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};
