class Solution
{
public:
    bool isPerfectSquare(int num)
    {

        for (long long i = 0; i <= num / 2; i++)
        {

            if (num == 1)
            {
                return true;
            }

            if (i * i == num)
            {
                return true;
            }
        }

        return false;
    }
};