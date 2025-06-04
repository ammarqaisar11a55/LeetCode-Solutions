class Solution {
public:
    int kthFactor(int n, int k) {
        int res = -1;

        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                k--;

                if (k == 0)
                    return i;
            }
        }

        return res;
    }
};
