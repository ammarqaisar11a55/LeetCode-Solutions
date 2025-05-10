class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<int> res(n, 1);
        long long mod = 1000000007;

        while (k--) {
            for (int i = 1; i < res.size(); i++) {
                res[i] = ((res[i - 1] + res[i])) % mod;
            }
        }
        
        return res[n - 1];
    }
};
