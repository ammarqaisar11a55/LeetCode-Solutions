class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {

        int res = numBottles;
        int used_water_bottles = 0;

        while (numBottles > 0)
        {
            used_water_bottles++;
            numBottles--;

            if (used_water_bottles == numExchange)
            {
                numBottles++;
                res++;
                used_water_bottles = 0;
            }
        }

        return res;
    }
};