class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {

        int res = 0;
        unordered_map<int, int> mp;

        for (int i : nums)
            mp[i]++;

        for (auto x : mp) {
            if (x.second % k == 0) {
                res += (x.first * x.second);
            }
        }

        return res;
    }
};
