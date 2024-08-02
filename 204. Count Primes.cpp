class Solution
{
public:
    int countPrimes(int n)
    {

        int count = 0;

        vector<bool> Primes(n + 1, true);

        Primes[0] = Primes[1] = false;

        for (int i = 2; i < n; i++)
        {
            if (Primes[i])
            {
                count++;

                for (int j = i * 2; j <= n; j += i)
                {
                    Primes[j] = false;
                }
            }
        }

        return count;
    }
};