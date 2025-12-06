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
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i : nums)
            mp[i]++;

        unordered_set<int> primes_st;

        Sieve_of_Eratosthenes(100, primes_st);

        for (auto x : mp) {
            if (primes_st.find(x.second) != primes_st.end())
                return true;
        }

        return false;
    }
};
