class Solution {
public:
vector<int> Sieve(int N, int left)
{
    vector<bool> Primes(N + 1,true);

    Primes[0] = Primes[1] = false;

    for (long long i = 2; i <= N; i++)
    {
        if (Primes[i])
        {
            for (long long j = i * i; j <= N; j += i)
            {
                Primes[j] = false;
            }
        }
    }

    vector<int>Res;

    for(int i = left; i <= N; i++)
    {
        if(Primes[i])
        {
            Res.push_back(i);
        }
    }

    return Res;
}

    vector<int> closestPrimes(int left, int right) {
     vector<int> Primes = Sieve(right,left);

    if(Primes.size() <= 1)
        return {-1,-1};

    int Min_Diff = INT_MAX;

    int Num1 = -1;
    int Num2 = -1;

    for(int i = 0; i < Primes.size() - 1; i++)
    {
        if(Primes[i + 1] - Primes[i] < Min_Diff)
        {
            Min_Diff = Primes[i + 1] - Primes[i];
            Num1 = Primes[i];
            Num2 = Primes[i + 1];
        }
    }

    return {Num1,Num2};   
    }
};
