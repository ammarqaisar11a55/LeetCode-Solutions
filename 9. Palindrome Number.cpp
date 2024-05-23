class Solution
{
public:
    bool isPalindrome(int x)
    {

        long long copy = x;
        long long rev = 0;

        while (x != 0)
        {
            rev = rev * 10 + x % 10;
            x = x / 10;
        }

        if (rev == copy && rev >= 0)
        {
            return true;
        }
        else
            return false;
    }
};