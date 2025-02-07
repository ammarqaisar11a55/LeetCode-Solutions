class Solution
{
public:
    int minOperations(int n)
    {
        vector<int> nums(n);

        for (int i = 0; i < n; i++)
        {
            nums[i] = (2 * i) + 1;
        }

        int operations = 0;

        while (n > -1)
        {
            int s = 0;
            int e = n - 1;

            while (s < e)
            {
                operations++;
                nums[s++]++;
                nums[e--]--;
            }

            n--;
        }

        return operations;
    }
};