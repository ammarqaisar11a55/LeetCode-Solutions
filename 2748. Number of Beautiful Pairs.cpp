class Solution
{
public:
    int GCD(int a, int b)
    {
        if (a == 0)
            return b;

        return GCD(b % a, a);
    }

    int countBeautifulPairs(vector<int> &nums)
    {

        int totalpairs = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {

                string temp1 = to_string(nums[i]);
                string temp2 = to_string(nums[j]);

                int gcd = GCD(temp1[0] - '0', temp2[temp2.length() - 1] - '0');

                if (gcd == 1)
                    totalpairs++;
            }
        }

        return totalpairs;
    }
};