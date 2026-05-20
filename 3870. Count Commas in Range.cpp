class Solution {
public:
    int countCommas(int n) {
        int ans = 0;

        for (int i = 1000; i <= n; i++)
            ans++;

        return ans;
    }
};