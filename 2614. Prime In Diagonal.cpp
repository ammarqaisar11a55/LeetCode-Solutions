class Solution
{
public:
    void Sieve(int n, unordered_set<int> &D)
    {
        vector<bool> Primes(n + 1, true);

        Primes[0] = Primes[1] = false;

        for (int i = 2; i * i <= n; i++)
        {
            if (Primes[i])
            {
                for (long long j = (long long)i * i; j <= n; j += i)
                {
                    Primes[j] = false;
                }
            }
        }

        for (int i = 0; i <= n; i++)
        {
            if (Primes[i])
            {
                D.insert(i);
            }
        }
    }

    int diagonalPrime(vector<vector<int>> &nums)
    {

        int Maxi = INT_MIN;
        unordered_set<int> Diagonals;

        for (int i = 0; i < nums.size(); i++)
        {
            Diagonals.insert(nums[i][i]);
            Diagonals.insert(nums[i][nums.size() - 1 - i]);
        }

        for (auto it = Diagonals.begin(); it != Diagonals.end(); it++)
        {
            Maxi = max(Maxi, *it);
        }

        unordered_set<int> DiagonalPrimes;

        Sieve(Maxi, DiagonalPrimes);

        int Ans = INT_MIN;

        for (auto it = Diagonals.begin(); it != Diagonals.end(); it++)
        {
            if (DiagonalPrimes.find(*it) != DiagonalPrimes.end())
                Ans = max(Ans, *it);
        }

        return Ans == INT_MIN ? 0 : Ans;
    }
};