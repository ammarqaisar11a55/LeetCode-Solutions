class Solution
{
public:
    int countLargestGroup(int n)
    {

        unordered_map<int, int> Mp;
        int Maxi = INT_MIN;

        for (int i = 1; i <= n; i++)
        {
            int sum = 0;
            int N = i;
            while (N != 0)
            {
                sum += N % 10;
                N /= 10;
            }

            Mp[sum]++;
            Maxi = max(Maxi, Mp[sum]);
        }

        int count = 0;

        for (auto x : Mp)
            if (x.second == Maxi)
                count++;

        return count;
    }
};