class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<int, int> mp;

        for (char c : s) {
            mp[c]++;
        }

        if (k > mp.size())
            return 0;

        vector<int> freq;

        for (auto x : mp) {
            freq.push_back(x.second);
        }

        sort(freq.rbegin(), freq.rend());

        int res = 0;

        while (freq.size() != k) {
            res += freq.back();
            freq.pop_back();
        }

        return res;
    }
};
