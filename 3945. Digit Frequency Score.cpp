class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int, int> mp;

        while (n > 0) {
            mp[n % 10]++;
            n /= 10;
        }

        int res = 0;

        for (auto x : mp) {
            res += x.first * x.second;
        }

        return res;
    }
};
