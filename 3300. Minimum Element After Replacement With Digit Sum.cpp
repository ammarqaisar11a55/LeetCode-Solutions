class Solution
{
public:
    int sum(int x)
    {
        int sum = 0;

        while (x != 0)
        {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int minElement(vector<int> &nums)
    {

        int Ans = INT_MAX;

        for (int x : nums)
            Ans = min(Ans, sum(x));

        return Ans;
    }
};