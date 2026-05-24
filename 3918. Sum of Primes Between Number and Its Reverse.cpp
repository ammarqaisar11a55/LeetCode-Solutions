class Solution {
public:
    void Sieve_of_Eratosthenes(int limit, unordered_set<int>& Res) {
        vector<bool> Primes(limit + 1, true);

        Primes[0] = Primes[1] = false;

        for (int i = 2; i * i <= limit; i++) {
            if (Primes[i]) {
                for (long long j = (long long)i * i; j <= limit; j += i) {
                    Primes[j] = false;
                }
            }
        }

        for (int i = 0; i < Primes.size(); i++) {
            if (Primes[i]) {
                Res.insert(i);
            }
        }
    }

    int sumOfPrimesInRange(int n) {
        int left = n;
        int right = 0;

        while (n > 0) {
            right = (right * 10) + (n % 10);
            n /= 10;
        }

        int limit = max(left, right);

        unordered_set<int> primes;

        Sieve_of_Eratosthenes(limit, primes);
        int res = 0;

        for (int i : primes) {
            if (i >= min(left, right) && i <= limit) {
                res += i;
            }
        }

        return res;
    }
};