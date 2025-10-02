class Solution {
public:
    int Euclidean_GCD(int a, int b) {
        if (a == 0) {
            return b;
        }

        return Euclidean_GCD(b % a, a);
    }

    int gcdOfOddEvenSums(int n) {
        int odd = 0, even = 0, n_copy = n;

        int current_num = 1;

        while (n--) {
            odd += current_num;
            current_num += 2;
        }

        current_num = 2;

        while (n_copy--) {
            even += current_num;
            current_num += 2;
        }

        return Euclidean_GCD(even, odd);
    }
};
