class Solution
{
public:
    int mySqrt(int x)
    {

        int s = 0;
        int e = x;
        long long int mid = s + (e - s) / 2;
        long long int ans = 0;

        while (s <= e)
        {
            if (mid * mid == x)
            {
                return mid;
            }
            else if (mid * mid > x)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
                ans = mid;
            }

            mid = s + (e - s) / 2;
        }

        return ans;
    }
};