class Solution
{
public:
    bool is_possible(string &squared, int target, int index, int sum)
    {
        if (index >= squared.length())
        {
            if (sum == target)
            {
                return true;
            }

            return false;
        }

        int num = 0;

        for (int i = index; i < squared.length(); i++)
        {
            num = num * 10 + (squared[i] - '0');

            if (num + sum > target)
                break;

            if (is_possible(squared, target, i + 1, num + sum))
                return true;
        }

        return false;
    }

    int punishmentNumber(int n)
    {

        int res = 0;

        for (int i = 1; i <= n; i++)
        {

            string squared = to_string(i * i);

            if (is_possible(squared, i, 0, 0))
            {
                res += i * i;
            }
        }

        return res;
    }
};