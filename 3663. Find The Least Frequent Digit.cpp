class Solution {
public:
    int getLeastFrequentDigit(int n) {
        unordered_map<int, int> mp;

        while (n > 0) {
            mp[n % 10]++;
            n /= 10;
        }

        int low_freq = INT_MAX;

        for (auto x : mp) {
            low_freq = min(low_freq, x.second);
        }

        int res = INT_MAX;

        for (auto x : mp) {
            if (x.second == low_freq) {
                res = min(res, x.first);
            }
        }

        return res;
    }
};
