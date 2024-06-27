class Solution
{
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k)
    {

        int ans = 0;

        for (int i = 1; i <= k; i++)
        {
            if (numOnes != 0)
            {
                ans += 1;
                numOnes--;
                continue;
            }

            if (numZeros != 0)
            {
                ans += 0;
                numZeros--;
                continue;
            }

            if (numNegOnes != 0)
            {
                ans -= 1;
                numNegOnes--;
                continue;
            }
        }

        return ans;
    }
};