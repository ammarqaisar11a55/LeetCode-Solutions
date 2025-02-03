class Solution
{
public:
    int digits_product(int n)
    {
        int res = 1;

        while (n != 0)
        {
            res *= n % 10;
            n /= 10;
        }

        return res;
    }

    int smallestNumber(int n, int t)
    {

        int res = 0;

        if (n % 10 == 0)
            return n;

        for (int i = n; i <= 100; i++)
        {
            if (n % 10 == 0)
            {
                return i;
            }
            else
            {

                int product = digits_product(i);

                if (product % t == 0)
                {
                    res = i;
                    break;
                }
            }
        }

        return res;
    }
};