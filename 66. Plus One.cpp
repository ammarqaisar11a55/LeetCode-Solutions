class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {

        reverse(digits.begin(), digits.end());

        for (int i = 0; i < digits.size(); i++)
        {
            if (digits[i] < 9)
            {
                digits[i]++;
                reverse(digits.begin(), digits.end());
                return digits;
            }

            digits[i] = 0;
        }

        digits.push_back(1);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};