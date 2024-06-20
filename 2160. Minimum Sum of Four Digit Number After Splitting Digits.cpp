class Solution
{
public:
    int minimumSum(int num)
    {

        vector<int> Digits(4, 0);

        Digits[0] = {num % 10};
        num /= 10;

        Digits[1] = {num % 10};
        num /= 10;

        Digits[2] = {num % 10};
        num /= 10;

        Digits[3] = {num % 10};
        num /= 10;

        sort(Digits.begin(), Digits.end());

        return (Digits[0] * 10 + Digits[2]) + (Digits[1] * 10 + Digits[3]);
    }
};