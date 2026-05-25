class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> res;

        vector<int> unique;

        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) == mp.end()) {
                unique.push_back(nums[i]);
                mp[nums[i]]++;
            } else {
                mp[nums[i]]++;
            }
        }

        for (int i : unique) {
            int n = i;
            int occ = mp[n];

            int repeat = min(k, occ);

            for (int j = 1; j <= repeat; j++) {
                res.push_back(n);
            }
        }

        return res;
    }
};