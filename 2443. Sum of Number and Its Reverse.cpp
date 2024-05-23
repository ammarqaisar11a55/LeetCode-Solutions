class Solution
{
public:
    bool sumOfNumberAndReverse(int num)
    {

        for (int i = 0; i < pow(10, 6); i++)
        {

            if (i + reverse(i) == num)
            {
                return true;
            }
        }

        return false;
    }

    int reverse(int x)
    {

        int rev = 0;

        while (x != 0)
        {

            rev = rev * 10 + x % 10;
            x = x / 10;
        }

        return rev;
    }
};