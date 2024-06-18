class Solution
{
public:
    int bitwiseComplement(int n)
    {

        if (n == 0)
        {
            return 1;
        }

        // Binary Conversion:

        vector<int> bits;

        while (n != 0)
        {
            bits.push_back(n % 2);
            n /= 2;
        }

        reverse(bits.begin(), bits.end());

        // Complement

        for (int i = 0; i < bits.size(); i++)
        {
            if (bits[i] == 1)
            {
                bits[i] = 0;
            }
            else
                bits[i] = 1;
        }

        int ans = 0;
        int j = 0;

        for (int i = bits.size() - 1; i >= 0; i--)
        {
            ans += (bits[i] * pow(2, j++));
        }

        return ans;
    }
};