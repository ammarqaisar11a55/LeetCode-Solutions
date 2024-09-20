class Solution
{
public:
    int divisorSubstrings(int num, int k)
    {

        int count = 0;
        string numinstring = to_string(num);

        for (int i = 0; i <= numinstring.length() - k; i++)
        {
            string substring = numinstring.substr(i, k);
            int val = stoi(substring);

            if (val != 0 && ((num % val) == 0))
                count++;
        }

        return count;
    }
};