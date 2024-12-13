class Solution
{
public:
    string toHex(int num)
    {

        string res;
        string T = "0123456789abcdef";

        if (num == 0)
            return "0";

        if (num > 0)
        {

            while (num > 0)
            {
                res = T[num % 16] + res;
                num /= 16;
            }
            return res;
        }

        unsigned int n = static_cast<unsigned int>(num); // Treat the number as unsigned

        while (n != 0)
        {
            res = T[n & 0xF] + res; // Get the last 4 bits
            n >>= 4;                // Right shift by 4 bits
        }
        return res;
    }
};