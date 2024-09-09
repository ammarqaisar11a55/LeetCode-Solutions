class Solution
{
public:
    int getLucky(string s, int k)
    {

        string conversion;

        for (char x : s)
            conversion += to_string(x - 'a' + 1);

        for (int i = 1; i <= k; i++)
        {
            int sum = 0;
            for (int j = 0; j < conversion.length(); j++)
            {
                sum += conversion[j] - '0';
            }

            conversion = to_string(sum);

            if (conversion.length() == 0 || conversion.length() == 1)
                return stoi(conversion);
        }

        return stoi(conversion);
    }
};