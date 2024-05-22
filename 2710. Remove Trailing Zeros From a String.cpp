class Solution
{
public:
    string removeTrailingZeros(string num)
    {

        int end = num.length() - 1;

        while (end >= 0)
        {
            if (num[end] == '0')
            {
                num.erase(num.begin() + end);
                end--;
            }
            else
                break;
        }

        return num;
    }
};