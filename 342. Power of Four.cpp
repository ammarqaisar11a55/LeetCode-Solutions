class Solution
{
public:
    bool isPowerOfFour(int n)
    {

        for (int i = 0; i < 31; i++)
        {
            if (n == (pow(4, i)))
            {
                return true;
            }
        }

        return false;
    }
};