class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> mp;

        for (char c : s)
            mp[c]++;

        int res = 0;

        for (auto x : mp) {
            if (x.second <= 2) {
                res += x.second;
            } else {
                if (x.second % 2 == 0) {
                    res += 2;

                } else
                    res++;
            }
        }

        return res;
    }
};
