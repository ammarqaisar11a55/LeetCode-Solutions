class Solution
{
public:
    int sumofdigits(int n)
    {
        int sum = 0;

        while (n != 0)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n)
    {

        int slow = n;
        int fast = sumofdigits(n);

        while (fast != 1 && fast != slow)
        {
            slow = sumofdigits(slow);
            fast = sumofdigits(sumofdigits(fast));
        }

        return fast == 1 ? true : false;
    }
};