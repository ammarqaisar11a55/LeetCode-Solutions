
class Solution
{
public:
    int addDigits(int num)
    {
        if (num < 10)
        {
            return num;
        }

        while (num >= 10)
        {
            num = DigitsSum(num);
        }

        return num;
    }

    int DigitsSum(int x)
    {
        int sum = 0;

        while (x != 0)
        {
            sum += x % 10;
            x /= 10;
        }

        return sum;
    }
};
