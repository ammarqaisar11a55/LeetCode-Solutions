class Solution
{
public:
    int numberOfChild(int n, int k)
    {

        int ans = 0;
        int direction = 1;

        while (k--)
        {

            if (direction == 1)
            {
                ans++;

                if (ans == n - 1)
                {
                    direction = direction * -1;
                }
            }
            else
            {
                ans--;

                if (ans == 0)
                {
                    direction = abs(direction);
                }
            }
        }

        return ans;
    }
};