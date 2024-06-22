
class Solution
{
public:
    int countSymmetricIntegers(int low, int high)
    {
        int count = 0;

        for (int i = low; i <= high; i++)
        {
            if (is_symmetric(i))
                count++;
        }
        return count;
    }

    bool is_symmetric(int x)
    {
        if ((to_string(x)).length() % 2 != 0)
            return false;

        string N = to_string(x);

        string FirstHalve;
        string SecondHalve;

        for (int i = 0; i < N.length() / 2; i++)
        {
            FirstHalve.push_back(N[i]);
        }

        for (int i = N.length() / 2; i < N.length(); i++)
        {
            SecondHalve.push_back(N[i]);
        }

        int First = stoi(FirstHalve);
        int Second = stoi(SecondHalve);

        if (DigitsSum(First) == DigitsSum(Second))
            return true;

        return false;
    }

    int DigitsSum(int x)
    {
        int sum = 0;

        while (x != 0)
        {
            sum += x % 10;
            x /= 10;
        }

        return sum;
    }
};
