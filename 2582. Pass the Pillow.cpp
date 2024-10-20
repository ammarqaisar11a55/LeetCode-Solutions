class Solution
{
public:
    int passThePillow(int n, int time)
    {

        int ans = 1;

        int direction = 1;

        while (time--)
        {
            if (direction == 1)
            {
                ans++;

                if (ans >= n)
                {
                    direction = direction * -1;
                }
            }
            else
            {
                ans--;

                if (ans <= 1)
                {
                    direction = abs(direction);
                }
            }
        }

        return ans;
    }
};