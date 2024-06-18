class Solution
{
public:
    string convertToBase7(int num)
    {

        if (num == 0)
        {
            return "0";
        }

        string base7 = "";

        bool negative = false;

        if (num < 0)
        {
            negative = true;
            num = num * -1;
        }

        while (num != 0)
        {
            base7 += (to_string(num % 7));
            num /= 7;
        }

        reverse(base7.begin(), base7.end());

        if (negative)
        {
            return "-" + base7;
        }

        return base7;
    }
};