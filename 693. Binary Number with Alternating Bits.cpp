class Solution
{
public:
    bool hasAlternatingBits(int n)
    {

        vector<int> binary;

        while (n != 0)
        {
            binary.push_back(n % 2);
            n /= 2;
        }

        for (int i = 0; i < binary.size() - 1; i++)
        {
            if (binary[i] == binary[i + 1])
            {
                return false;
            }
        }

        return true;
    }
};