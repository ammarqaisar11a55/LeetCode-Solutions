class Solution {
public:
    long long removeZeros(long long n) {

        long long int res = 0;

        while (n > 0) {
            int digit = n % 10;

            if (digit != 0) {
                res = (res * 10) + digit;
            }

            n /= 10;
        }

        long long int fres = 0;

        while (res > 0) {
            int digit = res % 10;

            fres = (fres * 10) + digit;

            res /= 10;
        }

        return fres;
    }
};
