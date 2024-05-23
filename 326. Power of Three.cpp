class Solution
{
public:
    bool isPowerOfThree(int n)
    {

        for (int i = 0; i < 31; i++)
        {
            if (n == (pow(3, i)))
            {
                return true;
            }
        }

        return false;
    }
};