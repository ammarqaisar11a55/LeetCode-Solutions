class Solution
{
public:
    bool nonZero(int x)
    {
        while (x != 0)
        {
            if (x % 10 == 0)
                return false;

            x /= 10;
        }

        return true;
    }

    vector<int> getNoZeroIntegers(int n)
    {

        vector<int> Ans;

        int a = 1;
        int b = n - 1;

        while (true)
        {
            if (nonZero(a) && nonZero(b))
            {
                Ans.push_back(a);
                Ans.push_back(b);
                break;
            }
            else
            {
                a++;
                b--;
            }
        }

        return Ans;
    }
};