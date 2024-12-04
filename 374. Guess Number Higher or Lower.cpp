/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guessNumber(int n)
    {

        int s = 1;
        int e = n;
        int picked_number = 0;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (guess(mid) == 0)
            {
                picked_number = mid;
                break;
            }
            else if (guess(mid) == 1)
            {
                s = mid + 1;
            }
            else
                e = mid - 1;
        }

        return picked_number;
    }
};