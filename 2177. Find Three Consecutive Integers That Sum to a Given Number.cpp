class Solution
{
public:
    vector<long long> sumOfThree(long long num)
    {

        long long x = num / 3;

        return (3 * x == num) ? vector<long long>{x - 1, x, x + 1} : vector<long long>{};
    }
};