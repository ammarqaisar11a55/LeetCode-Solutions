class Solution
{
public:
    int distanceTraveled(int mainTank, int additionalTank)
    {

        int distance = 0;
        int consumed = 0;

        while (mainTank > 0)
        {

            if (mainTank > 0)
            {
                distance += 10;
                consumed++;
                mainTank--;
            }
            if (consumed % 5 == 0 && additionalTank != 0)
            {
                mainTank++;
                additionalTank--;
            }
        }

        return distance;
    }
};