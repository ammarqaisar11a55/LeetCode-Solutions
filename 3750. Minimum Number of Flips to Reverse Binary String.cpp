class Solution {
public:
    int minimumFlips(int n) {
        string original;

        while (n > 0) {
            original += ('0' + (n % 2));
            n /= 2;
        }

        string reversed = original;
        reverse(reversed.begin(), reversed.end());

        int res = 0;

        for (int i = 0; i < reversed.length(); i++) {
            if (reversed[i] != original[i]) {
                res++;
            }
        }

        return res;
    }
};
