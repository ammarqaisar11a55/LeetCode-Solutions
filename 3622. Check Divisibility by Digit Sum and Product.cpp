class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, product = 1;

        int n_copy = n;

        while (n > 0) {
            sum = sum + n % 10;
            product = product * (n % 10);

            n /= 10;
        }

        return n_copy % ((sum + product)) == 0 ? true : false;
    }
};
