class Solution
{
public:
    vector<int> evenOddBit(int n)
    {

        int even_count = 0;
        int odd_count = 0;

        vector<int> bits;

        while (n != 0)
        {
            bits.push_back(n % 2);
            n /= 2;
        }

        for (int i = 0; i < bits.size(); i++)
        {
            if (bits[i] == 1)
            {
                if (i % 2 == 0)
                {
                    even_count++;
                }
                else
                    odd_count++;
            }
        }

        return {even_count, odd_count};
    }
};